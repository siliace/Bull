#ifndef BULL_RENDER_CONTEXT_WGL_WGLCREATECONTEXTARB_HPP
#define BULL_RENDER_CONTEXT_WGL_WGLCREATECONTEXTARB_HPP

#include <Bull/Render/Context/Extension.hpp>

#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB               0x2093
#define WGL_CONTEXT_FLAGS_ARB                     0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126
#define WGL_CONTEXT_DEBUG_BIT_ARB                 0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    0x0002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_VERSION_ARB                 0x2095
#define ERROR_INVALID_PROFILE_ARB                 0x2096

namespace Bull
{
    namespace prv
    {
        HGLRC (WINAPI* wglCreateContextAttribs)(HDC hDC, HGLRC hShareContext, const int *attribList) = nullptr;

        Extension wglCreateContext("WGL_ARB_create_context", []
        {
            wglCreateContextAttribs = reinterpret_cast<HGLRC (WINAPI*)(HDC, HGLRC, const int*)>(GlContext::getFunction("wglCreateContextAttribsARB"));

            return wglCreateContextAttribs != nullptr;
        });
    }
}

#endif // BULL_RENDER_CONTEXT_WGL_WGLCREATECONTEXTARB_HPP
