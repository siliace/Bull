#ifndef Bull_ContextSettings_hpp
#define Bull_ContextSettings_hpp

#include <Bull/Core/Integer.hpp>

namespace Bull
{
    struct ContextSettings
    {
        Uint8 depths  = 24;
        Uint8 stencil = 8;
    };
}

#endif // Bull_ContextSettings_hpp
