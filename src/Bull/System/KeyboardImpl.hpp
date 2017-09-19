#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/KeyboardImpl.hpp>
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_XLIB
        #include <Bull/System/Xlib/KeyboardImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/System/XCB/KeyboardImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
