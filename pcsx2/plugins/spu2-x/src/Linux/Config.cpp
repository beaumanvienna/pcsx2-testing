/* SPU2-X, A plugin for Emulating the Sound Processing Unit of the Playstation 2
 * Developed and maintained by the Pcsx2 Development Team.
 *
 * Original portions from SPU2ghz are (c) 2008 by David Quintana [gigaherz]
 *
 * SPU2-X is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Lesser General Public License as published by the Free Software Found-
 * ation, either version 3 of the License, or (at your option) any later version.
 *
 * SPU2-X is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with SPU2-X.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Global.h"
#include "Dialogs.h"
#include "Config.h"

#ifdef __unix__
#include <SDL.h>
#include <SDL_audio.h>
#endif

#ifdef PCSX2_DEVBUILD
static const int LATENCY_MAX = 3000;
#else
static const int LATENCY_MAX = 750;
#endif

static const int LATENCY_MIN = 3;
static const int LATENCY_MIN_TIMESTRETCH = 15;

int AutoDMAPlayRate[2] = {0, 0};

// Default settings.

// MIXING
int Interpolation = 4;
/* values:
		0: no interpolation (use nearest)
		1. linear interpolation
		2. cubic interpolation
		3. hermite interpolation
		4. catmull-rom interpolation
*/

bool EffectsDisabled = false;
float FinalVolume; // global
bool AdvancedVolumeControl;
float VolumeAdjustFLdb; // decibels settings, cos audiophiles love that
float VolumeAdjustCdb;
float VolumeAdjustFRdb;
float VolumeAdjustBLdb;
float VolumeAdjustBRdb;
float VolumeAdjustSLdb;
float VolumeAdjustSRdb;
float VolumeAdjustLFEdb;
float VolumeAdjustFL; // linear coefs calculated from decibels,
float VolumeAdjustC;
float VolumeAdjustFR;
float VolumeAdjustBL;
float VolumeAdjustBR;
float VolumeAdjustSL;
float VolumeAdjustSR;
float VolumeAdjustLFE;
unsigned int delayCycles;

bool postprocess_filter_enabled = true;
bool postprocess_filter_dealias = false;
bool _visual_debug_enabled = false; // windows only feature

// OUTPUT
u32 OutputModule = 0;
int SndOutLatencyMS = 300;
int SynchMode = 0; // Time Stretch, Async or Disabled
static u32 OutputAPI = 0;
static u32 SdlOutputAPI = 0;

int numSpeakers = 0;
int dplLevel = 0;
bool temp_debug_state;

/*****************************************************************************/

void ReadSettings()
{
    // For some reason this can be called before we know what ini file we're writing to.
    // Lets not try to read it if that happens.
    if (!pathSet) {
        FileLog("Read called without the path set.\n");
        return;
    }

    Interpolation = CfgReadInt(L"MIXING", L"Interpolation", 4);
    EffectsDisabled = CfgReadBool(L"MIXING", L"Disable_Effects", false);
    postprocess_filter_dealias = CfgReadBool(L"MIXING", L"DealiasFilter", false);
    FinalVolume = ((float)CfgReadInt(L"MIXING", L"FinalVolume", 100)) / 100;
    if (FinalVolume > 1.0f)
        FinalVolume = 1.0f;

    AdvancedVolumeControl = CfgReadBool(L"MIXING", L"AdvancedVolumeControl", false);
    VolumeAdjustCdb = CfgReadFloat(L"MIXING", L"VolumeAdjustC(dB)", 0);
    VolumeAdjustFLdb = CfgReadFloat(L"MIXING", L"VolumeAdjustFL(dB)", 0);
    VolumeAdjustFRdb = CfgReadFloat(L"MIXING", L"VolumeAdjustFR(dB)", 0);
    VolumeAdjustBLdb = CfgReadFloat(L"MIXING", L"VolumeAdjustBL(dB)", 0);
    VolumeAdjustBRdb = CfgReadFloat(L"MIXING", L"VolumeAdjustBR(dB)", 0);
    VolumeAdjustSLdb = CfgReadFloat(L"MIXING", L"VolumeAdjustSL(dB)", 0);
    VolumeAdjustSRdb = CfgReadFloat(L"MIXING", L"VolumeAdjustSR(dB)", 0);
    VolumeAdjustLFEdb = CfgReadFloat(L"MIXING", L"VolumeAdjustLFE(dB)", 0);
    VolumeAdjustC = powf(10, VolumeAdjustCdb / 10);
    VolumeAdjustFL = powf(10, VolumeAdjustFLdb / 10);
    VolumeAdjustFR = powf(10, VolumeAdjustFRdb / 10);
    VolumeAdjustBL = powf(10, VolumeAdjustBLdb / 10);
    VolumeAdjustBR = powf(10, VolumeAdjustBRdb / 10);
    VolumeAdjustSL = powf(10, VolumeAdjustSLdb / 10);
    VolumeAdjustSR = powf(10, VolumeAdjustSRdb / 10);
    VolumeAdjustLFE = powf(10, VolumeAdjustLFEdb / 10);
    delayCycles = CfgReadInt(L"DEBUG", L"DelayCycles", 4);

    wxString temp;

#if SDL_MAJOR_VERSION >= 2
    CfgReadStr(L"OUTPUT", L"Output_Module", temp, SDLOut->GetIdent());
#else
    CfgReadStr(L"OUTPUT", L"Output_Module", temp, PortaudioOut->GetIdent());
#endif
    OutputModule = FindOutputModuleById(temp.c_str()); // find the driver index of this module

// find current API
#ifdef __linux__
    CfgReadStr(L"PORTAUDIO", L"HostApi", temp, L"ALSA");
    if (temp == L"OSS")
        OutputAPI = 1;
    else if (temp == L"JACK")
        OutputAPI = 2;
    else // L"ALSA"
        OutputAPI = 0;
#else
    CfgReadStr(L"PORTAUDIO", L"HostApi", temp, L"OSS");
    OutputAPI = 0; // L"OSS"
#endif

#ifdef __unix__
    CfgReadStr(L"SDL", L"HostApi", temp, L"pulseaudio");
    SdlOutputAPI = 0;
#if SDL_MAJOR_VERSION >= 2
    // YES It sucks ...
    for (int i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
        if (!temp.Cmp(wxString(SDL_GetAudioDriver(i), wxConvUTF8)))
            SdlOutputAPI = i;
    }
#endif
#endif

    SndOutLatencyMS = CfgReadInt(L"OUTPUT", L"Latency", 300);
    SynchMode = CfgReadInt(L"OUTPUT", L"Synch_Mode", 0);

    PortaudioOut->ReadSettings();
#ifdef __unix__
    SDLOut->ReadSettings();
#endif
    SoundtouchCfg::ReadSettings();
    DebugConfig::ReadSettings();

    // Sanity Checks
    // -------------

    Clampify(SndOutLatencyMS, LATENCY_MIN, LATENCY_MAX);

    if (mods[OutputModule] == NULL) {
        fwprintf(stderr, L"* SPU2-X: Unknown output module '%s' specified in configuration file.\n", temp.wc_str());
        fprintf(stderr, "* SPU2-X: Defaulting to SDL (%S).\n", SDLOut->GetIdent());
        OutputModule = FindOutputModuleById(SDLOut->GetIdent());
    }

    WriteSettings();
    spuConfig->Flush();
}

/*****************************************************************************/

void WriteSettings()
{
    if (!pathSet) {
        FileLog("Write called without the path set.\n");
        return;
    }

    CfgWriteInt(L"MIXING", L"Interpolation", Interpolation);
    CfgWriteBool(L"MIXING", L"Disable_Effects", EffectsDisabled);
    CfgWriteBool(L"MIXING", L"DealiasFilter", postprocess_filter_dealias);
    CfgWriteInt(L"MIXING", L"FinalVolume", (int)(FinalVolume * 100 + 0.5f));

    CfgWriteBool(L"MIXING", L"AdvancedVolumeControl", AdvancedVolumeControl);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustC(dB)", VolumeAdjustCdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustFL(dB)", VolumeAdjustFLdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustFR(dB)", VolumeAdjustFRdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustBL(dB)", VolumeAdjustBLdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustBR(dB)", VolumeAdjustBRdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustSL(dB)", VolumeAdjustSLdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustSR(dB)", VolumeAdjustSRdb);
    CfgWriteFloat(L"MIXING", L"VolumeAdjustLFE(dB)", VolumeAdjustLFEdb);

    CfgWriteStr(L"OUTPUT", L"Output_Module", mods[OutputModule]->GetIdent());
    CfgWriteInt(L"OUTPUT", L"Latency", SndOutLatencyMS);
    CfgWriteInt(L"OUTPUT", L"Synch_Mode", SynchMode);
    CfgWriteInt(L"DEBUG", L"DelayCycles", delayCycles);

    PortaudioOut->WriteSettings();
#ifdef __unix__
    SDLOut->WriteSettings();
#endif
    SoundtouchCfg::WriteSettings();
    DebugConfig::WriteSettings();
}

void advanced_dialog()
{
    SoundtouchCfg::DisplayDialog();
}

void debug_dialog()
{
    DebugConfig::DisplayDialog();
}

#if defined(__unix__)

// Format the slider with ms.
static gchar *cb_scale_format_ms(GtkScale *scale, gdouble value)
{
    return g_strdup_printf("%g ms (avg)", value);
}

// Format the slider with a % sign.
static gchar *cb_scale_format_percent(GtkScale *scale, gdouble value)
{
    return g_strdup_printf("%g %%", value);
}

// Disables and reenables the debug button.
static void cb_toggle_sensitivity(GtkWidget *widget, gpointer data)
{
    GtkButton *btn = static_cast<GtkButton *>(data);

    temp_debug_state = !temp_debug_state;
    gtk_widget_set_sensitive(GTK_WIDGET(btn), temp_debug_state);
}

static void cb_adjust_latency(GtkComboBox *widget, gpointer data)
{
    GtkRange *range = static_cast<GtkRange *>(data);
    // Minimum latency for timestretch is 15ms. Everything else is 3ms.
    const int min_latency = gtk_combo_box_get_active(widget) == 0 ? LATENCY_MIN_TIMESTRETCH : LATENCY_MIN;
    gtk_range_set_range(range, min_latency, LATENCY_MAX);
}

void DisplayDialog()
{
    int return_value;

    GtkWidget *dialog;
    GtkWidget *main_box;

    GtkWidget *mixing_frame, *mixing_box;
    GtkWidget *int_label, *int_box;
    GtkWidget *effects_check;
    GtkWidget *dealias_filter;
    GtkWidget *debug_check, *debug_button, *debug_frame, *debug_box;

    GtkWidget *output_frame, *output_box;
    GtkWidget *mod_label, *mod_box;
    GtkWidget *api_label, *api_box;
#if SDL_MAJOR_VERSION >= 2
    GtkWidget *sdl_api_label, *sdl_api_box;
#endif
    GtkWidget *latency_label, *latency_slide;
    GtkWidget *volume_label, *volume_slide;
    GtkWidget *sync_label, *sync_box;
    GtkWidget *advanced_button;

    /* Create the widgets */
    dialog = gtk_dialog_new_with_buttons(
        "SPU2-X Config",
        NULL, /* parent window*/
        (GtkDialogFlags)(GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT),
        "Cancel", GTK_RESPONSE_REJECT,
        "OK", GTK_RESPONSE_ACCEPT,
        NULL);

    int_label = gtk_label_new("Interpolation:");
    int_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(int_box), "0 - Nearest (Fastest/bad quality)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(int_box), "1 - Linear (Simple/okay sound)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(int_box), "2 - Cubic (Artificial highs)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(int_box), "3 - Hermite (Better highs)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(int_box), "4 - Catmull-Rom (PS2-like/slow)");
    gtk_combo_box_set_active(GTK_COMBO_BOX(int_box), Interpolation);

    effects_check = gtk_check_button_new_with_label("Disable Effects Processing");
    dealias_filter = gtk_check_button_new_with_label("Use the de-alias filter (Overemphasizes the highs)");

    debug_check = gtk_check_button_new_with_label("Enable Debug Options");
    debug_button = gtk_button_new_with_label("Configure...");

    mod_label = gtk_label_new("Module:");
    mod_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(mod_box), "0 - No Sound (Emulate SPU2 only)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(mod_box), "1 - PortAudio (Cross-platform)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(mod_box), "2 - SDL Audio (Recommended for PulseAudio)");
    //gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(mod_box), "3 - Alsa (probably doesn't work)");
    gtk_combo_box_set_active(GTK_COMBO_BOX(mod_box), OutputModule);

    api_label = gtk_label_new("PortAudio API:");
    api_box = gtk_combo_box_text_new();
#ifdef __linux__
    // In order to keep it the menu light, I only put linux major api
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(api_box), "0 - ALSA (recommended)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(api_box), "1 - OSS (legacy)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(api_box), "2 - JACK");
#else
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(api_box), "OSS");
#endif
    gtk_combo_box_set_active(GTK_COMBO_BOX(api_box), OutputAPI);

#if SDL_MAJOR_VERSION >= 2
    sdl_api_label = gtk_label_new("SDL API:");
    sdl_api_box = gtk_combo_box_text_new();
    // YES It sucks ...
    for (int i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(sdl_api_box), SDL_GetAudioDriver(i));
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(sdl_api_box), SdlOutputAPI);
#endif

    latency_label = gtk_label_new("Latency:");
    const int min_latency = SynchMode == 0 ? LATENCY_MIN_TIMESTRETCH : LATENCY_MIN;

    latency_slide = ps_gtk_hscale_new_with_range(min_latency, LATENCY_MAX, 5);
    gtk_range_set_value(GTK_RANGE(latency_slide), SndOutLatencyMS);

    volume_label = gtk_label_new("Volume:");

    volume_slide = ps_gtk_hscale_new_with_range(0, 100, 5);
    gtk_range_set_value(GTK_RANGE(volume_slide), FinalVolume * 100);

    sync_label = gtk_label_new("Synchronization Mode:");
    sync_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(sync_box), "TimeStretch (Recommended)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(sync_box), "Async Mix (Breaks some games!)");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(sync_box), "None (Audio can skip.)");
    gtk_combo_box_set_active(GTK_COMBO_BOX(sync_box), SynchMode);

    advanced_button = gtk_button_new_with_label("Advanced...");

    main_box = ps_gtk_hbox_new(5);

    mixing_box = ps_gtk_vbox_new(5);
    mixing_frame = gtk_frame_new("Mixing Settings:");
    gtk_container_add(GTK_CONTAINER(mixing_frame), mixing_box);


    output_box = ps_gtk_vbox_new(5);
    output_frame = gtk_frame_new("Output Settings:");

    debug_box = ps_gtk_vbox_new(5);
    debug_frame = gtk_frame_new("Debug Settings:");

    gtk_container_add(GTK_CONTAINER(debug_box), debug_check);
    gtk_container_add(GTK_CONTAINER(debug_box), debug_button);
    gtk_container_add(GTK_CONTAINER(debug_frame), debug_box);

    gtk_container_add(GTK_CONTAINER(output_frame), output_box);

    gtk_container_add(GTK_CONTAINER(mixing_box), int_label);
    gtk_container_add(GTK_CONTAINER(mixing_box), int_box);
    gtk_container_add(GTK_CONTAINER(mixing_box), effects_check);
    gtk_container_add(GTK_CONTAINER(mixing_box), dealias_filter);
    gtk_container_add(GTK_CONTAINER(mixing_box), debug_frame);

    gtk_container_add(GTK_CONTAINER(output_box), mod_label);
    gtk_container_add(GTK_CONTAINER(output_box), mod_box);
    gtk_container_add(GTK_CONTAINER(output_box), api_label);
    gtk_container_add(GTK_CONTAINER(output_box), api_box);
#if SDL_MAJOR_VERSION >= 2
    gtk_container_add(GTK_CONTAINER(output_box), sdl_api_label);
    gtk_container_add(GTK_CONTAINER(output_box), sdl_api_box);
#endif
    gtk_container_add(GTK_CONTAINER(output_box), sync_label);
    gtk_container_add(GTK_CONTAINER(output_box), sync_box);
    gtk_container_add(GTK_CONTAINER(output_box), latency_label);
    gtk_container_add(GTK_CONTAINER(output_box), latency_slide);
    gtk_container_add(GTK_CONTAINER(output_box), volume_label);
    gtk_container_add(GTK_CONTAINER(output_box), volume_slide);
    gtk_container_add(GTK_CONTAINER(output_box), advanced_button);

    gtk_box_pack_start(GTK_BOX(main_box), mixing_frame, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(main_box), output_frame, TRUE, TRUE, 5);

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(effects_check), EffectsDisabled);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dealias_filter), postprocess_filter_dealias);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(debug_check), DebugEnabled);
    gtk_widget_set_sensitive(GTK_WIDGET(debug_button), DebugEnabled);
    temp_debug_state = DebugEnabled;

    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(dialog))), main_box);
    gtk_widget_show_all(dialog);

    g_signal_connect(volume_slide, "format_value", G_CALLBACK(cb_scale_format_percent), volume_slide);
    g_signal_connect(latency_slide, "format_value", G_CALLBACK(cb_scale_format_ms), latency_slide);
    g_signal_connect(sync_box, "changed", G_CALLBACK(cb_adjust_latency), latency_slide);

    g_signal_connect(debug_check, "clicked", G_CALLBACK(cb_toggle_sensitivity), debug_button);
    g_signal_connect_swapped(advanced_button, "clicked", G_CALLBACK(advanced_dialog), advanced_button);
    g_signal_connect_swapped(debug_button, "clicked", G_CALLBACK(debug_dialog), debug_button);

    return_value = gtk_dialog_run(GTK_DIALOG(dialog));

    if (return_value == GTK_RESPONSE_ACCEPT) {
        DebugEnabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(debug_check));
        postprocess_filter_dealias = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(dealias_filter));
        if (gtk_combo_box_get_active(GTK_COMBO_BOX(int_box)) != -1)
            Interpolation = gtk_combo_box_get_active(GTK_COMBO_BOX(int_box));

        EffectsDisabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(effects_check));

        if (gtk_combo_box_get_active(GTK_COMBO_BOX(mod_box)) != -1)
            OutputModule = gtk_combo_box_get_active(GTK_COMBO_BOX(mod_box));

        if (gtk_combo_box_get_active(GTK_COMBO_BOX(api_box)) != -1) {
            OutputAPI = gtk_combo_box_get_active(GTK_COMBO_BOX(api_box));
#ifdef __linux__
            switch (OutputAPI) {
                case 0:
                    PortaudioOut->SetApiSettings(L"ALSA");
                    break;
                case 1:
                    PortaudioOut->SetApiSettings(L"OSS");
                    break;
                case 2:
                    PortaudioOut->SetApiSettings(L"JACK");
                    break;
                default:
                    PortaudioOut->SetApiSettings(L"Unknown");
            }
#else
            switch (OutputAPI) {
                case 0:
                    PortaudioOut->SetApiSettings(L"OSS");
                    break;
                default:
                    PortaudioOut->SetApiSettings(L"Unknown");
            }
#endif
        }

#if SDL_MAJOR_VERSION >= 2
        if (gtk_combo_box_get_active(GTK_COMBO_BOX(sdl_api_box)) != -1) {
            SdlOutputAPI = gtk_combo_box_get_active(GTK_COMBO_BOX(sdl_api_box));
            // YES It sucks ...
            SDLOut->SetApiSettings(wxString(SDL_GetAudioDriver(SdlOutputAPI), wxConvUTF8));
        }
#endif
        FinalVolume = gtk_range_get_value(GTK_RANGE(volume_slide)) / 100;
        SndOutLatencyMS = gtk_range_get_value(GTK_RANGE(latency_slide));

        if (gtk_combo_box_get_active(GTK_COMBO_BOX(sync_box)) != -1)
            SynchMode = gtk_combo_box_get_active(GTK_COMBO_BOX(sync_box));
    }

    gtk_widget_destroy(dialog);
}
#else
void DisplayDialog()
{
}
#endif

void configure()
{
    initIni();
    ReadSettings();
    DisplayDialog();
    WriteSettings();
    delete spuConfig;
    spuConfig = NULL;
}
