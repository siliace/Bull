#ifndef Bull_WGLCreateContextARB_hpp
#define Bull_WGLCreateContextARB_hpp

#include <windows.h>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

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
        bool loadCreateContextARB();

        HGLRC (WINAPI* wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList) = nullptr;

        ExtensionsLoader::Extension WglCreateContextARB("WGL_ARB_create_context", []{
                                                            wglCreateContextAttribsARB = reinterpret_cast<HGLRC (WINAPI*)(HDC, HGLRC, const int*)>(GlContext::getFunction("wglCreateContextAttribsARB"));

                                                            return wglCreateContextAttribsARB != nullptr;
                                                        });
    }
}

#endif // Bull_WGLCreateContextARB_hpp
