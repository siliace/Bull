#ifndef BULL_CURSORSYSTEMHANDLER_HPP
#define BULL_CURSORSYSTEMHANDLER_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Support/Win32/Windows.hpp>
#endif

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef HCURSOR CursorHandler;
        #elif defined BULL_OS_OSX
            #error Lack of implementation : CursorHandler
        #elif defined BULL_OS_GNU_LINUX
            typedef unsigned long CursorHandler;
        #endif
    }
}

#endif //BULL_CURSORSYSTEMHANDLER_HPP
