#ifndef BULL_CURSORSYSTEMHANDLER_HPP
#define BULL_CURSORSYSTEMHANDLER_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
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
            #if defined BULL_WEYLAND
                #error Lack of implementation : CursorHandler
            #elif defined BULL_XCB
                typedef Uint32 CursorHandler;
            #elif defined BULL_XLIB
                typedef unsigned long CursorHandler;
            #endif
        #endif
    }
}

#endif //BULL_CURSORSYSTEMHANDLER_HPP
