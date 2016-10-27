#ifndef Bull_ContextSettings_hpp
#define Bull_ContextSettings_hpp

#include <Bull/Core/Integer.hpp>

namespace Bull
{
    struct BULL_API ContextSettings
    {
        unsigned int major = 4;
        unsigned int minor = 5;
        Uint8 depths  = 24;
        Uint8 stencil = 8;
    };
}

#endif // Bull_ContextSettings_hpp
