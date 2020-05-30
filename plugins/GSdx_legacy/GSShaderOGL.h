/*
 *	Copyright (C) 2011-2013 Gregory hainaut
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

class GSShaderOGL {
	GLuint m_pipeline;
	hash_map<uint64, GLuint > m_single_prog;
	const bool m_debug_shader;

	bool ValidateShader(GLuint p);
	bool ValidateProgram(GLuint p);
	bool ValidatePipeline(GLuint p);

	std::string GenGlslHeader(const std::string& entry, GLenum type, const std::string& macro);
	GLuint LinkNewProgram();

	public:
	GSShaderOGL(bool debug);
	~GSShaderOGL();

	void GS(GLuint s);
	void PS(GLuint s);
	void VS(GLuint s);

	void UseProgram();

	GLuint Compile(const std::string& glsl_file, const std::string& entry, GLenum type, const char* glsl_h_code, const std::string& macro_sel = "");

	int DumpAsm(const std::string& file, GLuint p);

	void Delete(GLuint s);
};
