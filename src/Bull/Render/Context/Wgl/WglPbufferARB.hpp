#ifndef BULL_RENDER_CONTEXT_WGL_WGLPBUFFER_HPP
#define BULL_RENDER_CONTEXT_WGL_WGLPBUFFER_HPP

#include <Bull/Render/Context/Extension.hpp>
#include <Bull/Render/Context/Wgl/PBufferHandler.hpp>

#define WGL_DRAW_TO_PBUFFER_ARB    0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB 0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB  0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB 0x2030
#define WGL_PBUFFER_LARGEST_ARB    0x2033
#define WGL_PBUFFER_WIDTH_ARB      0x2034
#define WGL_PBUFFER_HEIGHT_ARB     0x2035
#define WGL_PBUFFER_LOST_ARB       0x2036

namespace Bull
{
    namespace prv
    {
        HPBUFFER (WINAPI* wglCreatePbuffer)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) = nullptr;

        HDC (WINAPI* wglGetPbufferDC)(HPBUFFER hPbuffer) = nullptr;

        int (WINAPI* wglReleasePbufferDC)(HPBUFFER hPbuffer, HDC hDC) = nullptr;

        BOOL (WINAPI* wglDestroyPbuffer)(HPBUFFER hPbuffer) = nullptr;

        BOOL (WINAPI* wglQueryPbuffer)(HPBUFFER hPbuffer, int iAttribute, int* piValue) = nullptr;

        Extension wglPbuffer("WGL_ARB_pbuffer", []
        {
            wglCreatePbuffer = reinterpret_cast<HPBUFFER (WINAPI*)(HDC, int, int, int, const int*)>(GlContext::getFunction("wglCreatePbufferARB"));
            wglGetPbufferDC = reinterpret_cast<HDC (WINAPI*)(HPBUFFER)>(GlContext::getFunction("wglGetPbufferDCARB"));
            wglReleasePbufferDC = reinterpret_cast<int (WINAPI*)(HPBUFFER, HDC hDC)>(GlContext::getFunction("wglReleasePbufferDCARB"));
            wglDestroyPbuffer = reinterpret_cast<BOOL (WINAPI*)(HPBUFFER)>(GlContext::getFunction("wglDestroyPbufferARB"));
            wglQueryPbuffer = reinterpret_cast<BOOL (WINAPI*)(HPBUFFER, int, int*)>(GlContext::getFunction("wglQueryPbufferARB"));

            return wglCreatePbuffer && wglGetPbufferDC && wglReleasePbufferDC && wglDestroyPbuffer && wglQueryPbuffer;
        });
    }
}

#endif // BULL_RENDER_CONTEXT_WGL_WGLPBUFFER_HPP
