#ifndef Bull_GLXSWAPCONTROLGLI_hpp
#define Bull_GLXSWAPCONTROLGLI_hpp

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

#endif // Bull_GLXSWAPCONTROLGLI_hpp
