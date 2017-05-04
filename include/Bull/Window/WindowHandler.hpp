#ifndef BULL_WINDOWHANDLER_HPP
#define BULL_WINDOWHANDLER_HPP

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

#endif // BULL_WINDOWHANDLER_HPP
