#ifndef BULL_WINDOWHANDLER_HPP
#define BULL_WINDOWHANDLER_HPP

#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Core/Support/Win32/Windows.hpp>

#endif


namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
        typedef HWND__* WindowHandler;
        #elif defined BULL_OS_GNU_LINUX
        typedef unsigned long WindowHandler;
        #endif
    }
}

#endif // BULL_WINDOWHANDLER_HPP
