#ifndef Bull_WindowHandler_hpp
#define Bull_WindowHandler_hpp

#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    struct HWND__;
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef HWND__* WindowHandler;
    #elif defined BULL_OS_GNU_LINUX
        typedef unsigned long WindowHandler;
    #endif
}

#endif // Bull_WindowHandler_hpp
