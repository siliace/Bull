#ifndef Bull_WglMultisample_hpp
#define Bull_WglMultisample_hpp

#include <Bull/Render/Context/ExtensionsLoader.hpp>

#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB        0x2042

namespace Bull
{
    namespace prv
    {
        ExtensionsLoader::Extension WglMultisample("WGL_ARB_multisample", []
        {
            return true;
        });
    }
}

#endif // Bull_WglMultisample_hpp
