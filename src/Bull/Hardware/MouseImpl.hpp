#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/MouseImpl.hpp>
#else
    #if defined BULL_XLIB
        #include <Bull/Hardware/Xlib/MouseImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Hardware/XCB/MouseImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
