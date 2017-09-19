#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/MouseImpl.hpp>
#else
    #if defined BULL_XLIB
        #include <Bull/System/Xlib/MouseImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/System/XCB/MouseImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
