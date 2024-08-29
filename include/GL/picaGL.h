#ifndef __PICAGL_H__
#define __PICAGL_H__

#include <GL/gl.h>

#ifdef __cplusplus
extern "C" {
#endif

void pglInit();
void pglExit();
void pglSwapBuffers();
void pglSelectScreen(unsigned display, unsigned side);
GLvoid* pglNormalizeTextureFormat(const GLvoid* inData, GLint* internalFormat,
								GLsizei* ioWidth, GLsizei* ioHeight,
								GLenum* ioFormat, GLenum* ioType, bool forcePO2);

#ifdef __cplusplus
}
#endif

#endif