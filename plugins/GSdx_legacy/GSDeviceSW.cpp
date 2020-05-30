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
#include "GSDeviceSW.h"

GSDeviceSW::GSDeviceSW()
{
}

bool GSDeviceSW::Create(GSWnd* wnd)
{
	if(!GSDevice::Create(wnd))
		return false;

	Reset(1, 1);

	return true;
}

bool GSDeviceSW::Reset(int w, int h)
{
	if(!GSDevice::Reset(w, h))
		return false;

	// TODO: m_backbuffer should be a window wrapper, or some native bitmap, software-only StretchRect to a full screen window may be too slow

	m_backbuffer = new GSTextureSW(GSTexture::RenderTarget, w, h);

	return true;
}

GSTexture* GSDeviceSW::CreateSurface(int type, int w, int h, bool msaa, int format)
{
	if(format != 0) return NULL; // there is only one format

	return new GSTextureSW(type, w, h);
}

void GSDeviceSW::BeginScene()
{
	// TODO
}

void GSDeviceSW::DrawPrimitive()
{
	// TODO
}

void GSDeviceSW::EndScene()
{
	// TODO
}

void GSDeviceSW::ClearRenderTarget(GSTexture* t, const GSVector4& c)
{
	Clear(t, (c * 255 + 0.5f).rgba32());
}

void GSDeviceSW::ClearRenderTarget(GSTexture* t, uint32 c)
{
	Clear(t, c);
}

void GSDeviceSW::ClearDepth(GSTexture* t, float c)
{
	Clear(t, *(uint32*)&c);
}

void GSDeviceSW::ClearStencil(GSTexture* t, uint8 c)
{
	Clear(t, c);
}

GSTexture* GSDeviceSW::CopyOffscreen(GSTexture* src, const GSVector4& sRect, int w, int h, int format, int ps_shader)
{
	GSTexture* dst = CreateOffscreen(w, h, format);

	if(dst != NULL)
	{
		CopyRect(src, dst, GSVector4i(0, 0, w, h));
	}

	return dst;
}

void GSDeviceSW::CopyRect(GSTexture* sTex, GSTexture* dTex, const GSVector4i& r)
{
	GSTexture::GSMap m;

	if(sTex->Map(m, &r))
	{
		dTex->Update(r, m.bits, m.pitch);

		sTex->Unmap();
	}
}

class ShaderBase
{
protected:
	GSVector4i Sample(const GSVector4i& c, const GSVector4i& uf, const GSVector4i& vf) const
	{
		GSVector4i c0 = c.upl8();
		GSVector4i c1 = c.uph8();

		c0 = c0.lerp16<0>(c1, vf);
		c0 = c0.lerp16<0>(c0.srl<8>(), uf);

		return c0;
	}

	GSVector4i Blend(const GSVector4i& c0, const GSVector4i& c1) const
	{
		return c0.lerp16<0>(c1, c1.wwwwl().sll16(7));
	}

	GSVector4i Blend2x(const GSVector4i& c0, const GSVector4i& c1) const
	{
		return c0.lerp16<0>(c1, c1.wwwwl().sll16(1).pu16().uph8().sll16(7)); // .sll16(1).pu16() => 2x, then clamp (...)
	}

	GSVector4i Blend(const GSVector4i& c0, const GSVector4i& c1, const GSVector4i& f) const
	{
		return c0.lerp16<0>(c1, f);
	}
};

class ShaderCopy : public ShaderBase
{
public:
	void operator() (uint32* RESTRICT dst, const GSVector4i& c, const GSVector4i& uf, const GSVector4i& vf) const
	{
		*dst = Sample(c, uf, vf).pu16().extract32<0>();
	}

	void operator() (uint32* RESTRICT dst, uint32 c) const
	{
		*dst = c;
	}
};

class ShaderAlphaBlend : public ShaderBase
{
public:
	void operator() (uint32* RESTRICT dst, const GSVector4i& c, const GSVector4i& uf, const GSVector4i& vf) const
	{
		*dst = Blend(Sample(c, uf, vf), GSVector4i(*dst).uph8()).pu16().extract32<0>();
	}

	void operator() (uint32* RESTRICT dst, uint32 c) const
	{
		*dst = Blend(GSVector4i(c), GSVector4i(*dst).uph8()).pu16().extract32<0>();
	}
};

class ShaderAlpha2xBlend : public ShaderBase
{
public:
	void operator() (uint32* RESTRICT dst, const GSVector4i& c, const GSVector4i& uf, const GSVector4i& vf) const
	{
		*dst = Blend2x(Sample(c, uf, vf), GSVector4i(*dst).uph8()).pu16().extract32<0>();
	}

	void operator() (uint32* RESTRICT dst, uint32 c) const
	{
		*dst = Blend2x(GSVector4i(c), GSVector4i(*dst).uph8()).pu16().extract32<0>();
	}
};

__aligned(class, 16) ShaderFactorBlend : public ShaderBase
{
	GSVector4i m_f;

public:
	ShaderFactorBlend(uint32 f)
	{
		m_f = GSVector4i((f << 16) | f).xxxx().srl16(1);
	}

	void operator() (uint32* RESTRICT dst, const GSVector4i& c, const GSVector4i& uf, const GSVector4i& vf) const
	{
		*dst = Blend(Sample(c, uf, vf), GSVector4i(*dst).uph8(), m_f).pu16().extract32<0>();
	}

	void operator() (uint32* RESTRICT dst, uint32 c) const
	{
		*dst = Blend(GSVector4i(c), GSVector4i(*dst).uph8(), m_f).pu16().extract32<0>();
	}
};

template<class SHADER> static void StretchRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, const SHADER& shader, bool linear)
{
	GSVector4i r(dRect.ceil());

	r = r.rintersect(GSVector4i(dTex->GetSize()).zwxy());

	if(r.rempty()) return;

	GSTexture::GSMap dm;

	if(!dTex->Map(dm, &r)) return;

	GSTexture::GSMap sm;

	if(!sTex->Map(sm, NULL)) {dTex->Unmap(); return;}

	GSVector2i ssize = sTex->GetSize();

	GSVector4 p = dRect;
	GSVector4 t = sRect * GSVector4(ssize).xyxy() * GSVector4((float)0x10000);

	GSVector4 tl = p.xyxy(t);
	GSVector4 br = p.zwzw(t);
	GSVector4 tlbr = br - tl;

	tlbr /= tlbr.xyxy();

	if(tl.x < (float)r.left) tl.z += tlbr.z * ((float)r.left - tl.x);
	if(tl.y < (float)r.top) tl.w += tlbr.w * ((float)r.top - tl.y);

	GSVector4i uvdudv(tl.zwzw(tlbr));

	GSVector4i uv = uvdudv.xxyy() + GSVector4i(0, 0x10000).xyxy();
	GSVector4i du = uvdudv.zzzz().srl<8>();
	GSVector4i dv = uvdudv.wwww().sll<8>();

	// TODO: clipping may not be that necessary knowing we don't address outside (except the linear filter +1 pixel)

	GSVector4i uvmax = GSVector4i((ssize.x - 1) << 16, (ssize.y - 1) << 16).xxyy();

	GSVector4i v = uv;

	if(linear)
	{
		for(int j = r.height(); j > 0; j--, v += dv, dm.bits += dm.pitch)
		{
			GSVector4i vf = v.zzwwh().zzww().srl16(1);
			GSVector4i vi = v.max_i16(GSVector4i::zero()).min_i16(uvmax);

			int v0 = vi.extract16<5>();
			int v1 = vi.extract16<7>();

			uint32* RESTRICT src0 = (uint32*)&sm.bits[v0 * sm.pitch];
			uint32* RESTRICT src1 = (uint32*)&sm.bits[v1 * sm.pitch];
			uint32* RESTRICT dst = (uint32*)dm.bits;

			GSVector4i u = v;

			for(int i = r.width(); i > 0; i--, dst++, u += du)
			{
				GSVector4i uf = u.xxyyh().xxyy().srl16(1);
				GSVector4i ui = u.max_i16(GSVector4i::zero()).min_i16(uvmax);

				int u0 = ui.extract16<1>();
				int u1 = ui.extract16<3>();

				shader(dst, GSVector4i(src0[u0], src0[u1], src1[u0], src1[u1]), uf, vf);
			}
		}
	}
	else
	{
		for(int j = r.height(); j > 0; j--, v += dv, dm.bits += dm.pitch)
		{
			GSVector4i vi = v.max_i16(GSVector4i::zero()).min_i16(uvmax);

			uint32* RESTRICT src = (uint32*)&sm.bits[vi.extract16<5>() * sm.pitch];
			uint32* RESTRICT dst = (uint32*)dm.bits;

			GSVector4i u = v;

			for(int i = r.width(); i > 0; i--, dst++, u += du)
			{
				GSVector4i ui = u.max_i16(GSVector4i::zero()).min_i16(uvmax);

				shader(dst, src[ui.extract16<1>()]);
			}
		}
	}

	sTex->Unmap();
	dTex->Unmap();
}

void GSDeviceSW::StretchRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, int shader, bool linear)
{
	// TODO: if dTex == m_backbuffer && m_backbuffer is special

	if(shader == 0)
	{
		if((sRect == GSVector4(0, 0, 1, 1) & dRect == GSVector4(dTex->GetSize()).zwxy()).alltrue() && sTex->GetSize() == dTex->GetSize())
		{
			// shortcut

			CopyRect(sTex, dTex, GSVector4i(dTex->GetSize()).zwxy());

			return;
		}

		ShaderCopy s;

		::StretchRect(sTex, sRect, dTex, dRect, s, linear);
	}
	else if(shader == 1)
	{
		ShaderAlphaBlend s;

		::StretchRect(sTex, sRect, dTex, dRect, s, linear);
	}
	else
	{
		ASSERT(0);
	}
}

void GSDeviceSW::PSSetShaderResources(GSTexture* sr0, GSTexture* sr1)
{
	// TODO
}

void GSDeviceSW::PSSetShaderResource(int i, GSTexture* sRect)
{
	// TODO
}

void GSDeviceSW::OMSetRenderTargets(GSTexture* rt, GSTexture* ds, const GSVector4i* scissor)
{
	// TODO
}

//

void GSDeviceSW::DoMerge(GSTexture* sTex[2], GSVector4* sRect, GSTexture* dTex, GSVector4* dRect, bool slbg, bool mmod, const GSVector4& c)
{
	ClearRenderTarget(dTex, c);

	if(sTex[1] && !slbg)
	{
		StretchRect(sTex[1], sRect[1], dTex, dRect[1]);
	}

	if(sTex[0])
	{
		if(mmod == 0)
		{
			// alpha = min(sTex[0].a * 2, 1)

			ShaderAlpha2xBlend s;

			::StretchRect(sTex[0], sRect[0], dTex, dRect[0], s, true);
		}
		else
		{
			// alpha = c.a

			ShaderFactorBlend s((uint32)(int)(c.a * 255));

			::StretchRect(sTex[0], sRect[0], dTex, dRect[0], s, true);
		}
	}

	// dTex->Save("c:\\1.bmp");
}

void GSDeviceSW::DoInterlace(GSTexture* sTex, GSTexture* dTex, int shader, bool linear, float yoffset)
{
	GSVector4 s = GSVector4(dTex->GetSize());

	GSVector4 sRect(0, 0, 1, 1);
	GSVector4 dRect(0.0f, yoffset, s.x, s.y + yoffset);

	if(shader == 0 || shader == 1)
	{
		// TODO: 0/1 => update even/odd lines of dTex
	}
	else if(shader == 2)
	{
		// TODO: blend lines (1:2:1 filter)
	}
	else if(shader == 3)
	{
		StretchRect(sTex, sRect, dTex, dRect, 0, linear);
	}
	else
	{
		ASSERT(0);
	}
}

void GSDeviceSW::Clear(GSTexture* t, uint32 c)
{
	int w = t->GetWidth();
	int h = t->GetHeight();

	GSTexture::GSMap m;

	if(t->Map(m, NULL))
	{
		GSVector4i v((int)c);

		w >>= 2;

		for(int j = 0; j < h; j++, m.bits += m.pitch)
		{
			GSVector4i* RESTRICT dst = (GSVector4i*)m.bits;

			for(int i = 0; i < w; i += 2)
			{
				dst[i + 0] = v;
				dst[i + 1] = v;
			}
		}

		t->Unmap();
	}
}

