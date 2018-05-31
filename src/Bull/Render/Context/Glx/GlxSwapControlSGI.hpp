#ifndef BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLSGI_HPP
#define BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLSGI_HPP

#include <Bull/Core/Support/Xlib/Xlib.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        namespace sgi
        {
            int (*glXSwapInterval)(int interval) = nullptr;
        }

        Extension glxSwapControlSGI("GLX_SGI_swap_control", [] {
            sgi::glXSwapInterval = reinterpret_cast<int (*)(int)>(GlContext::getFunction("glXSwapIntervalSGI"));

            return sgi::glXSwapInterval;
        });
    }
}

#endif // BULL_RENDER_CONTEXT_GLX_GLXSWAPCONTROLSGI_HPP
