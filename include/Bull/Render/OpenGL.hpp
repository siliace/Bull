#ifndef Bull_OpenGL_hpp
#define Bull_OpenGL_hpp

#include <GL/gl.h>
#include <GL/glcorearb.h>
#include <GL/glext.h>

#include <Bull/Core/System/Export.hpp>

BULL_API extern PFNGLBINDBUFFERPROC               glBindBuffer;
BULL_API extern PFNGLBINDVERTEXARRAYPROC          glBindVertexArray;
BULL_API extern PFNGLBUFFERDATAPROC               glBufferData;
BULL_API extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
BULL_API extern PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray;
BULL_API extern PFNGLGENBUFFERSPROC               glGenBuffers;
BULL_API extern PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays;
BULL_API extern PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer;

#endif // Bull_OpenGL_hpp
