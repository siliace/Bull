#ifndef Bull_WglSwapControlEXT_hpp
#define Bull_WglSwapControlEXT_hpp

#include <Bull/Render/Context/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        BOOL (WINAPI* wglSwapInterval)(int interval) = nullptr;
        int (WINAPI* wglGetSwapInterval)() = nullptr;

        ExtensionsLoader::Extension WglSwapControlEXT("WGL_EXT_swap_control", []
        {
            wglSwapInterval    = reinterpret_cast<BOOL (WINAPI*)(int)>(GlContext::getFunction("wglSwapIntervalEXT"));
            wglGetSwapInterval = reinterpret_cast<int (WINAPI*)()>(GlContext::getFunction("wglGetSwapIntervalEXT"));

            return wglSwapInterval && wglGetSwapInterval;
        });
    }
}

#endif // Bull_WglSwapControlEXT_hpp
