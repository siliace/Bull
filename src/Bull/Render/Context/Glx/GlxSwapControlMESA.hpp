#ifndef BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLMESA_HPP
#define BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLMESA_HPP

#include <Bull/Core/Support/Xlib/Xlib.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        namespace mesa
        {
            int (* glXSwapInterval)(int interval) = nullptr;

            int (* glXGetSwapInterval)() = nullptr;
        }

        Extension glxSwapControlMESA("GLX_MESA_swap_control", []
        {
            mesa::glXSwapInterval = reinterpret_cast<int (*)(int)>(GlContext::getFunction("glXSwapIntervalMESA"));
            mesa::glXGetSwapInterval = reinterpret_cast<int (*)()>(GlContext::getFunction("glXGetSwapIntervalMESA"));

            return mesa::glXSwapInterval && mesa::glXGetSwapInterval;
        });
    }
}

#endif // BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLMESA_HPP

