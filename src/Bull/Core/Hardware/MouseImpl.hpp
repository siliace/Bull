#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Hardware/Win32/MouseImpl.hpp>
#else
    #if defined BULL_XLIB
        #include <Bull/Core/Hardware/Xlib/MouseImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Core/XCB/MouseImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
