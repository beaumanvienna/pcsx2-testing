/*
 *	Copyright (C) 2011-2011 Gregory hainaut
 *	Copyright (C) 2007-2009 Gabest
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

#pragma once

#include "GSTexture.h"

namespace PboPool {
	void BindPbo();
	void UnbindPbo();
	void NextPbo();
	void NextPboWithSync();

	char* Map(uint32 size);
	void Unmap();
	uptr Offset();
	void EndTransfer();

	void Init();
	void Destroy();
}

class GSTextureOGL final : public GSTexture
{
	private:
		GLuint m_texture_id;	 // the texture id
		int m_pbo_size;
		GLuint m_fbo_read;
		bool m_dirty;
		bool m_clean;

		uint8* m_local_buffer;
		// Avoid alignment constrain
		//GSVector4i m_r;
		int m_r_x;
		int m_r_y;
		int m_r_w;
		int m_r_h;


		// internal opengl format/type/alignment
		GLenum m_int_format;
		GLenum m_int_type;
		uint32 m_int_alignment;
		uint32 m_int_shift;

	public:
		explicit GSTextureOGL(int type, int w, int h, int format, GLuint fbo_read);
		virtual ~GSTextureOGL();

		void Invalidate() final;
		bool Update(const GSVector4i& r, const void* data, int pitch) final;
		bool Map(GSMap& m, const GSVector4i* r = NULL) final;
		void Unmap() final;
		bool Save(const string& fn, bool user_image = false, bool dds = false) final;

		bool IsBackbuffer() { return (m_type == GSTexture::Backbuffer); }
		bool IsDss() { return (m_type == GSTexture::DepthStencil); }

		uint32 GetID() final { return m_texture_id; }
		bool HasBeenCleaned() { return m_clean; }
		void WasAttached() { m_clean = false; m_dirty = true; }
		void WasCleaned() { m_clean = true; }

		uint32 GetMemUsage();
};
