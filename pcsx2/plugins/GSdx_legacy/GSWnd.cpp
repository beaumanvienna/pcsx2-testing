/*
 *	Copyright (C) 2011-2014 Gregory hainaut
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
#include "GSWnd.h"

void GSWndGL::PopulateGlFunction()
{
	*(void**)&(gl_ActiveTexture) = GetProcAddress("glActiveTexture");
	*(void**)&(gl_BlendColor) = GetProcAddress("glBlendColor");

	// Load mandatory function pointer
#define GL_EXT_LOAD_OPT(ext) *(void**)&(ext) = GetProcAddress(#ext, true)
	// Load extra function pointer
#define GL_EXT_LOAD(ext)     *(void**)&(ext) = GetProcAddress(#ext, true)

	GL_EXT_LOAD(glBlendEquationSeparate);
	GL_EXT_LOAD(glBlendFuncSeparate);
	GL_EXT_LOAD(glAttachShader);
	GL_EXT_LOAD(glBindBuffer);
	GL_EXT_LOAD(glBindBufferBase);
	GL_EXT_LOAD(glBindBufferRange);
	GL_EXT_LOAD(glBindFramebuffer);
	GL_EXT_LOAD(glBindSampler);
	GL_EXT_LOAD(glBindVertexArray);
	GL_EXT_LOAD(glBlitFramebuffer);
	GL_EXT_LOAD(glBufferData);
	GL_EXT_LOAD(glCheckFramebufferStatus);
	GL_EXT_LOAD(glClearBufferfv);
	GL_EXT_LOAD(glClearBufferiv);
	GL_EXT_LOAD(glClearBufferuiv);
	GL_EXT_LOAD(glColorMaski);
	GL_EXT_LOAD(glDeleteBuffers);
	GL_EXT_LOAD(glDeleteFramebuffers);
	GL_EXT_LOAD(glDeleteSamplers);
	GL_EXT_LOAD(glDeleteVertexArrays);
	GL_EXT_LOAD(glDetachShader);
	GL_EXT_LOAD(glDrawBuffers);
	GL_EXT_LOAD(glDrawElementsBaseVertex);
	GL_EXT_LOAD(glEnableVertexAttribArray);
	GL_EXT_LOAD(glFramebufferRenderbuffer);
	GL_EXT_LOAD(glFramebufferTexture2D);
	GL_EXT_LOAD(glGenBuffers);
	GL_EXT_LOAD(glGenFramebuffers);
	GL_EXT_LOAD(glGenSamplers);
	GL_EXT_LOAD(glGenVertexArrays);
	GL_EXT_LOAD(glGetBufferParameteriv);
	GL_EXT_LOAD(glGetDebugMessageLogARB);
	GL_EXT_LOAD_OPT(glDebugMessageCallback);
	GL_EXT_LOAD(glGetProgramInfoLog);
	GL_EXT_LOAD(glGetProgramiv);
	GL_EXT_LOAD(glGetShaderiv);
	GL_EXT_LOAD(glGetStringi);
	GL_EXT_LOAD(glIsFramebuffer);
	GL_EXT_LOAD(glMapBuffer);
	GL_EXT_LOAD(glMapBufferRange);
	GL_EXT_LOAD(glProgramParameteri);
	GL_EXT_LOAD(glSamplerParameterf);
	GL_EXT_LOAD(glSamplerParameteri);
	GL_EXT_LOAD(glShaderSource);
	GL_EXT_LOAD(glUniform1i);
	GL_EXT_LOAD(glUnmapBuffer);
	GL_EXT_LOAD(glVertexAttribIPointer);
	GL_EXT_LOAD(glVertexAttribPointer);
	GL_EXT_LOAD(glBufferSubData);
	GL_EXT_LOAD(glFenceSync);
	GL_EXT_LOAD(glDeleteSync);
	GL_EXT_LOAD(glClientWaitSync);
	GL_EXT_LOAD(glFlushMappedBufferRange);
	// Query object
	GL_EXT_LOAD(glBeginQuery);
	GL_EXT_LOAD(glEndQuery);
	GL_EXT_LOAD(glGetQueryiv);
	GL_EXT_LOAD(glGetQueryObjectiv);
	GL_EXT_LOAD(glGetQueryObjectuiv);
	GL_EXT_LOAD(glQueryCounter);
	GL_EXT_LOAD(glGetQueryObjecti64v);
	GL_EXT_LOAD(glGetQueryObjectui64v);
	GL_EXT_LOAD(glGetInteger64v);
	// GL4.0
	GL_EXT_LOAD_OPT(glBlendEquationSeparateiARB);
	GL_EXT_LOAD_OPT(glBlendFuncSeparateiARB);
	// GL4.1
	GL_EXT_LOAD_OPT(glCreateShaderProgramv);
	GL_EXT_LOAD_OPT(glBindProgramPipeline);
	GL_EXT_LOAD_OPT(glDeleteProgramPipelines);
	GL_EXT_LOAD_OPT(glGenProgramPipelines);
	GL_EXT_LOAD_OPT(glGetProgramPipelineiv);
	GL_EXT_LOAD_OPT(glGetProgramPipelineInfoLog);
	GL_EXT_LOAD_OPT(glValidateProgramPipeline);
	GL_EXT_LOAD_OPT(glUseProgramStages);
	GL_EXT_LOAD_OPT(glProgramUniform1i); // but no GL4.2
	GL_EXT_LOAD_OPT(glGetProgramBinary);
	GL_EXT_LOAD_OPT(glViewportIndexedf);
	GL_EXT_LOAD_OPT(glViewportIndexedfv);
	GL_EXT_LOAD_OPT(glScissorIndexed);
	GL_EXT_LOAD_OPT(glScissorIndexedv);
	// NO GL4.1
	GL_EXT_LOAD(glDeleteProgram);
	GL_EXT_LOAD(glDeleteShader);
	GL_EXT_LOAD(glCompileShader);
	GL_EXT_LOAD(glCreateProgram);
	GL_EXT_LOAD(glCreateShader);
	GL_EXT_LOAD(glUseProgram);
	GL_EXT_LOAD(glGetShaderInfoLog);
	GL_EXT_LOAD(glLinkProgram);
	// GL4.2
	GL_EXT_LOAD_OPT(glBindImageTexture);
	GL_EXT_LOAD_OPT(glMemoryBarrier);
	GL_EXT_LOAD(glTexStorage2D);
	// GL4.3
	GL_EXT_LOAD_OPT(glCopyImageSubData);
	GL_EXT_LOAD_OPT(glInvalidateTexImage);
	GL_EXT_LOAD_OPT(glPushDebugGroup);
	GL_EXT_LOAD_OPT(glPopDebugGroup);
	GL_EXT_LOAD_OPT(glDebugMessageInsert);
	GL_EXT_LOAD_OPT(glDebugMessageControl);
	// GL4.4
	GL_EXT_LOAD_OPT(glClearTexImage);
	GL_EXT_LOAD_OPT(glBufferStorage);

	// GL4.5
	GL_EXT_LOAD_OPT(glCreateTextures);
	GL_EXT_LOAD_OPT(glTextureStorage2D);
	GL_EXT_LOAD_OPT(glTextureSubImage2D);
	GL_EXT_LOAD_OPT(glCopyTextureSubImage2D);
	GL_EXT_LOAD_OPT(glBindTextureUnit);
	GL_EXT_LOAD_OPT(glGetTextureImage);
	GL_EXT_LOAD_OPT(glTextureParameteri);

	GL_EXT_LOAD_OPT(glCreateFramebuffers);
	GL_EXT_LOAD_OPT(glClearNamedFramebufferfv);
	GL_EXT_LOAD_OPT(glClearNamedFramebufferuiv);
	GL_EXT_LOAD_OPT(glClearNamedFramebufferiv);
	GL_EXT_LOAD_OPT(glNamedFramebufferTexture);
	GL_EXT_LOAD_OPT(glNamedFramebufferDrawBuffers);
	GL_EXT_LOAD_OPT(glNamedFramebufferReadBuffer);
	GL_EXT_LOAD_OPT(glCheckNamedFramebufferStatus);

	GL_EXT_LOAD_OPT(glCreateBuffers);
	GL_EXT_LOAD_OPT(glNamedBufferStorage);
	GL_EXT_LOAD_OPT(glNamedBufferData);
	GL_EXT_LOAD_OPT(glNamedBufferSubData);
	GL_EXT_LOAD_OPT(glMapNamedBuffer);
	GL_EXT_LOAD_OPT(glMapNamedBufferRange);
	GL_EXT_LOAD_OPT(glUnmapNamedBuffer);
	GL_EXT_LOAD_OPT(glFlushMappedNamedBufferRange);

	GL_EXT_LOAD_OPT(glCreateSamplers);
	GL_EXT_LOAD_OPT(glCreateProgramPipelines);

	GL_EXT_LOAD_OPT(glClipControl);
	GL_EXT_LOAD_OPT(glTextureBarrier);

	if (glCreateFramebuffers == NULL) {
		Emulate_DSA::Init();
	}
}
