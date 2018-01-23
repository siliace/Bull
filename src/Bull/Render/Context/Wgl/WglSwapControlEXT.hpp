#ifndef BULL_RENDER_CONTEXT_WGL_WGLSWAPCONTROLEXT_HPP
#define BULL_RENDER_CONTEXT_WGL_WGLSWAPCONTROLEXT_HPP

#include <Bull/Render/Context/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        BOOL (WINAPI* wglSwapInterval)(int interval) = nullptr;
        int (WINAPI* wglGetSwapInterval)() = nullptr;

        Extension wglSwapControl("WGL_EXT_swap_control", []
        {
            wglSwapInterval    = reinterpret_cast<BOOL (WINAPI*)(int)>(GlContext::getFunction("wglSwapIntervalEXT"));
            wglGetSwapInterval = reinterpret_cast<int (WINAPI*)()>(GlContext::getFunction("wglGetSwapIntervalEXT"));

            return wglSwapInterval && wglGetSwapInterval;
        });
    }
}

#endif // BULL_RENDER_CONTEXT_WGL_WGLSWAPCONTROLEXT_HPP
