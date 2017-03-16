#ifndef Bull_GlxSwapControlMESA_hpp
#define Bull_GlxSwapControlMESA_hpp

#include <X11/Xlib.h>

#include <Bull/Window/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        namespace mesa
        {
            int (*glXSwapInterval)(int interval) = nullptr;
            int (*glXGetSwapInterval)() = nullptr;
        }

        ExtensionsLoader::Extension GlxSwapControlMESA("GLX_MESA_swap_control", []
        {
            mesa::glXSwapInterval    = reinterpret_cast<int (*)(int)>(GlContext::getFunction("glXSwapIntervalMESA"));
            mesa::glXGetSwapInterval = reinterpret_cast<int (*)()>(GlContext::getFunction("glXGetSwapIntervalMESA"));

            return mesa::glXSwapInterval && mesa::glXGetSwapInterval;
        });
    }
}

#endif // Bull_GlxSwapControlMESA_hpp

