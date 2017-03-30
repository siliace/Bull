#ifndef Bull_GlxSwapControlGLI_hpp
#define Bull_GlxSwapControlGLI_hpp

#include <X11/Xlib.h>

#include <Bull/Window/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        namespace sgi
        {
            int (*glXSwapInterval)(int interval) = nullptr;
        }

        ExtensionsLoader::Extension GlxSwapControlSGI("GLX_SGI_swap_control", []
        {
            sgi::glXSwapInterval = reinterpret_cast<int (*)(int)>(GlContext::getFunction("glXSwapIntervalSGI"));

            return sgi::glXSwapInterval;
        });
    }
}

#endif // Bull_GlxSwapControlGLI_hpp
