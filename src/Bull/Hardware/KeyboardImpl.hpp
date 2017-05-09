#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/KeyboardImpl.hpp>
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_XLIB
        #include <Bull/Hardware/Xlib/KeyboardImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Hardware/XCB/KeyboardImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
