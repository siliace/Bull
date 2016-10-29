#ifndef Bull_ContextSettings_hpp
#define Bull_ContextSettings_hpp

#include <Bull/Core/Integer.hpp>

namespace Bull
{
    struct BULL_API ContextSettings
    {
        Uint8 major = 4;
        Uint8 minor = 5;
        Uint8 depths  = 24;
        Uint8 stencil = 8;
        Uint8 antialiasing = 0;
    };
}

#endif // Bull_ContextSettings_hpp
