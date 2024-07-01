#include "internal.h"

GLboolean glIsEnabled(GLenum cap)
{
	switch (cap)
	{
		case GL_DEPTH_TEST:          return pglState->depthTestState;
		case GL_POLYGON_OFFSET_FILL: return pglState->polygonOffsetState;
		case GL_STENCIL_TEST:        return pglState->stencilTestState;
		case GL_BLEND:               return pglState->blendState;
		case GL_SCISSOR_TEST:        return pglState->scissorState;
		case GL_CULL_FACE:           return pglState->cullState ;
		case GL_TEXTURE_2D:          return pglState->texUnitState[pglState->texUnitActive];
		case GL_ALPHA_TEST:          return pglState->alphaTestState;
		default: return GL_FALSE;
	}
}

const GLubyte* glGetString(GLenum name)
{
	switch(name)
	{
		case GL_RENDERER:
			return (GLubyte*)"DMP(R) PICA200";
		case GL_VERSION:
			return (GLubyte*)"1.1";
		case GL_VENDOR:
			return (GLubyte*)"MasterFeizz";
		default: 
			return (GLubyte*)"";
	}
}

void glGetIntegerv(GLenum pname, GLint *params)
{
	switch(pname) 
	{
		case GL_MAX_TEXTURE_SIZE:
			*params = 128;
			break;
		case GL_BLEND_SRC:
			*params = _convert_blendfactor_to_gl(pglState->blendSrcFunction);
			break;
		case GL_BLEND_DST:
			*params = _convert_blendfactor_to_gl(pglState->blendDstFunction);
			break;
	}
}

void glGetBooleanv(GLenum pname, GLboolean *params)
{
	switch(pname)
	{
		case GL_DEPTH_WRITEMASK:
			*params = (pglState->writeMask & (1 << 4)) > 0 ? GL_TRUE : GL_FALSE;
			break;
	}
}

void glGetFloatv(GLenum pname, GLfloat* data)
{
	switch(pname)
	{
		case GL_CURRENT_COLOR:
			data[0] = pglState->currentColor.r;
			data[1] = pglState->currentColor.g;
			data[2] = pglState->currentColor.b;
			data[3] = pglState->currentColor.a;
			break;
	}
}