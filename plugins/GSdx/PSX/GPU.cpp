/*
 *	Copyright (C) 2007-2009 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "stdafx.h"
#include "GSdx.h"
#include "GSUtil.h"
#include "Renderers/Null/GSDeviceNull.h"
#include "GPURendererSW.h"

#ifdef _WIN32

#include "GPUSettingsDlg.h"
#include "Renderers/DX11/GSDevice11.h"

static HRESULT s_hr = E_FAIL;

#endif

#define PSE_LT_GPU 2

static GPURenderer* s_gpu = NULL;

EXPORT_C_(uint32) PSEgetLibType()
{
	return PSE_LT_GPU;
}

EXPORT_C_(const char*) PSEgetLibName()
{
	return GSUtil::GetLibName();
}

EXPORT_C_(uint32) PSEgetLibVersion()
{
	static const uint32 version = 1;
	static const uint32 revision = 1;

	return version << 16 | revision << 8 | PLUGIN_VERSION;
}

static void InitVectors()
{
	GSVector4i::InitVectors();
	GSVector4::InitVectors();
#if _M_SSE >= 0x500
	GSVector8::InitVectors();
#endif
#if _M_SSE >= 0x501
	GSVector8i::InitVectors();
#endif

	GPUDrawScanlineCodeGenerator::InitVectors();
	GPULocalMemory::InitVectors();
	GPUSetupPrimCodeGenerator::InitVectors();
}

EXPORT_C_(int32) GPUinit()
{
	if(!GSUtil::CheckSSE())
	{
		return -1;
	}

	theApp.Init();

	InitVectors();

	return 0;
}

EXPORT_C_(int32) GPUshutdown()
{
	return 0;
}

EXPORT_C_(int32) GPUclose()
{
	delete s_gpu;

	s_gpu = NULL;

#ifdef _WIN32
	GSDevice11::FreeD3DCompiler();

	if(SUCCEEDED(s_hr))
	{
		::CoUninitialize();

		s_hr = E_FAIL;
	}

#endif

	return 0;
}

EXPORT_C_(int32) GPUopen(void* hWnd)
{
	GPUclose();

	if(!GSUtil::CheckSSE())
	{
		return -1;
	}

#ifdef _WIN32

	s_hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if(!GSUtil::CheckDirectX())
	{
		return -1;
	}

	if (!GSDevice11::LoadD3DCompiler())
		return -1;
#endif

	GPURendererType renderer = static_cast<GPURendererType>(theApp.GetConfigI("Renderer"));
	int threads = theApp.GetConfigI("extrathreads");

	switch(renderer)
	{
#ifdef _WIN32
	case GPURendererType::D3D11_SW: s_gpu = new GPURendererSW(new GSDevice11(), threads); break;
#endif
	case GPURendererType::NULL_Renderer: s_gpu = new GPURendererSW(new GSDeviceNull(), threads); break;
	default: // Fall back to D3D11/Null mode if unknown value is read. No one could possibly enter here anyway.
#ifdef _WIN32
		s_gpu = new GPURendererSW(new GSDevice11(), threads); break;
#else
		s_gpu = new GPURendererSW(new GSDeviceNull(), threads); break;
#endif
	}

	if(!s_gpu->Create(hWnd))
	{
		GPUclose();

		return -1;
	}

	return 0;
}

EXPORT_C_(int32) GPUconfigure()
{
	if(!GSUtil::CheckSSE())
	{
		return -1;
	}

	theApp.Init();

#ifdef _WIN32

	GPUSettingsDlg dlg;

	if(IDOK == dlg.DoModal())
	{
		GPUshutdown();
		GPUinit();
	}

#else

    // TODO: linux
#endif

	return 0;
}

EXPORT_C_(int32) GPUtest()
{
	if(!GSUtil::CheckSSE())
	{
		return -1;
	}

	return 0;
}

EXPORT_C GPUabout()
{
	// TODO
}

EXPORT_C GPUwriteDataMem(const uint8* mem, uint32 size)
{
	s_gpu->WriteData(mem, size);
}

EXPORT_C GPUwriteData(uint32 data)
{
	s_gpu->WriteData((uint8*)&data, 1);
}

EXPORT_C GPUreadDataMem(uint8* mem, uint32 size)
{
	s_gpu->ReadData(mem, size);
}

EXPORT_C_(uint32) GPUreadData()
{
	uint32 data = 0;

	s_gpu->ReadData((uint8*)&data, 1);

	return data;
}

EXPORT_C GPUwriteStatus(uint32 status)
{
	s_gpu->WriteStatus(status);
}

EXPORT_C_(uint32) GPUreadStatus()
{
	return s_gpu->ReadStatus();
}

EXPORT_C_(uint32) GPUdmaChain(const uint8* mem, uint32 addr)
{
	uint32 last[3];

	memset(last, 0xff, sizeof(last));

	do
	{
		if(addr == last[1] || addr == last[2])
		{
			break;
		}

		(addr < last[0] ? last[1] : last[2]) = addr;

		last[0] = addr;

		uint8 size = mem[addr + 3];

		if(size > 0)
		{
			s_gpu->WriteData(&mem[addr + 4], size);
		}

		addr = *(uint32*)&mem[addr] & 0xffffff;
	}
	while(addr != 0xffffff);

	return 0;
}

EXPORT_C_(uint32) GPUgetMode()
{
	// TODO

	return 0;
}

EXPORT_C GPUsetMode(uint32 mode)
{
	// TODO
}

EXPORT_C GPUupdateLace()
{
	s_gpu->VSync();
}

EXPORT_C GPUmakeSnapshot()
{
	s_gpu->MakeSnapshot("c:/"); // TODO
}

EXPORT_C GPUdisplayText(char* text)
{
	// TODO
}

EXPORT_C GPUdisplayFlags(uint32 flags)
{
	// TODO
}

EXPORT_C_(int32) GPUfreeze(uint32 type, GPUFreezeData* data)
{
	if(!data || data->version != 1)
	{
		return 0;
	}

	if(type == 0)
	{
		s_gpu->Defrost(data);

		return 1;
	}
	else if(type == 1)
	{
		s_gpu->Freeze(data);

		return 1;
	}
	else if(type == 2)
	{
		int slot = *(int*)data + 1;

		if(slot < 1 || slot > 9)
		{
			return 0;
		}

		// TODO

		return 1;
	}

	return 0;
}

EXPORT_C GPUgetScreenPic(uint8* mem)
{
	// TODO
}

EXPORT_C GPUshowScreenPic(uint8* mem)
{
	// TODO
}

EXPORT_C GPUcursor(int player, int x, int y)
{
	// TODO
}
