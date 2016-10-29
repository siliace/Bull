#ifndef Bull_GlxSwapControlEXT_hpp
#define Bull_GlxSwapControlEXT_hpp

#include <X11/Xlib.h>

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

#endif // Bull_GlxSwapControlEXT_hpp
