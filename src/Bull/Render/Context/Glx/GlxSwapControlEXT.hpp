#ifndef BULL_GLXSWAPCONTROLEXT_HPP
#define BULL_GLXSWAPCONTROLEXT_HPP

#include <Bull/Core/Support/Xlib/Xlib.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

#define GLX_SWAP_INTERVAL_EXT     0x20F1
#define GLX_MAX_SWAP_INTERVAL_EXT 0x20F2

namespace Bull
{
    namespace prv
    {
        namespace ext
        {
            void (*glXSwapInterval)(::Display* dpy, GLXDrawable drawable, int interval) = nullptr;
        }

        ExtensionsLoader::Extension GlxSwapControlEXT("GLX_EXT_swap_control", []
        {
            ext::glXSwapInterval = reinterpret_cast<void (*)(::Display*, GLXDrawable, int)>(GlContext::getFunction("glXSwapIntervalEXT"));

            return ext::glXSwapInterval;
        });
    }
}

#endif // BULL_GLXSWAPCONTROLEXT_HPP
