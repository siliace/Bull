#ifndef BULL_WINDOWHANDLER_HPP
#define BULL_WINDOWHANDLER_HPP

#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_XLIB
        #include <X11/Xlib.h>
    #elif defined BULL_XCB
        #include <xcb/xcb.h>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif


namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef HWND__* WindowHandler;
        #elif defined BULL_OS_GNU_LINUX
            #if defined BULL_XLIB
                typedef ::Window WindowHandler;
            #elif defined BULL_XCB
                typedef xcb_window_t WindowHandler;
            #elif defined BULL_WEYLAND
                #error Todo
            #endif
        #endif
    }
}

#endif // BULL_WINDOWHANDLER_HPP
