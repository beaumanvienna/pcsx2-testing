/*  OnePAD - author: arcum42(@gmail.com)
 *  Copyright (C) 2009
 *
 *  Based on ZeroPAD, author zerofrog@gmail.com
 *  Copyright (C) 2006-2007
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#pragma once
#include <string.h> // for memset
#define MAX_KEYS 24

enum KeyType {
    PAD_JOYBUTTONS = 0,
    PAD_AXIS,
    PAD_HAT,
    PAD_NULL = -1
};

extern void set_keyboard_key(int pad, int keysym, int index);
extern int get_keyboard_key(int pad, int keysym);
extern void set_key(int pad, int index, int value);
extern int get_key(int pad, int index);
extern bool IsAnalogKey(int index);

extern KeyType type_of_joykey(int pad, int index);
extern int key_to_button(int pad, int index);
extern int key_to_axis(int pad, int index);
extern bool key_to_axis_sign(int pad, int index);
extern bool key_to_axis_type(int pad, int index);
extern int key_to_hat_dir(int pad, int index);

extern int button_to_key(int button_id);
extern int axis_to_key(int full_axis, int sign, int axis_id);
extern int hat_to_key(int dir, int axis_id);

//extern int PadEnum[2][2]; // never used

class PADconf
{
    u32 ff_intensity;
    u32 sensibility;

public:
    union
    {
        struct
        {
            u16 forcefeedback : 1;
            u16 reverse_lx : 1;
            u16 reverse_ly : 1;
            u16 reverse_rx : 1;
            u16 reverse_ry : 1;
            u16 mouse_l : 1;
            u16 mouse_r : 1;
            u16 sixaxis_usb : 1;
            u16 sixaxis_pressure : 1;
            u16 _free : 7;             // The 8 remaining bits are unused, do what you wish with them ;)
        } pad_options[GAMEPAD_NUMBER]; // One for each pads
        u32 packed_options;            // Only first 8 bits of each 16 bits series are really used, rest is padding
    };

    u32 keys[GAMEPAD_NUMBER][MAX_KEYS];
    u32 log;
    u32 joyid_map;
    std::map<u32, u32> keysym_map[GAMEPAD_NUMBER];

    PADconf() { init(); }

    void init()
    {
        memset(&keys, 0, sizeof(keys));
        log = packed_options = joyid_map = 0;
        ff_intensity = 0x7FFF; // set it at max value by default
        sensibility = 100;   // set it at 100%
        for (int pad = 0; pad < GAMEPAD_NUMBER; pad++)
        {
            keysym_map[pad].clear();
            set_joyid((u32)pad, (u32)pad); // define id mapping for each gamepad
        }
    }

    void set_joyid(u32 pad, u32 joy_id)
    {
        int shift = 8 * pad;
        joyid_map &= ~(0xFF << shift);         // clear
        joyid_map |= (joy_id & 0xFF) << shift; // set
    }

    u32 get_joyid(u32 pad)
    {
        int shift = 8 * pad;
        return ((joyid_map >> shift) & 0xFF);
    }

    /**
	 * Return (a copy of) private memner ff_instensity
	 **/
    u32 get_ff_intensity()
    {
        return ff_intensity;
    }

    /**
	 * Set intensity while checking that the new value is within
	 * valid range, more than 0x7FFF will cause pad not to rumble(and less than 0 is obviously bad)
	 **/
    void set_ff_intensity(u32 new_intensity)
    {
        if (new_intensity <= 0x7FFF)
        {
            ff_intensity = new_intensity;
        }
    }

    /**
	 * Set sensibility value.
	 * There will be an upper range, and less than 0 is obviously wrong.
	 * We are doing object oriented code, so members are definitely not supposed to be public.
	 **/
    void set_sensibility(u32 new_sensibility)
    {
        if (new_sensibility > 0)
        {
            sensibility = new_sensibility;
        }
        else
        {
            sensibility = 1;
        }
        
    }

    u32 get_sensibility()
    {
        return sensibility;
    }
};
extern PADconf *conf;
