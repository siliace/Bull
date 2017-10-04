#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Hardware/Win32/KeyboardImpl.hpp>
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_XLIB
        #include <Bull/Core/Hardware/Xlib/KeyboardImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Core/XCB/KeyboardImpl.hpp>
    #elif defined BULL_WEYLAND
        #error Todo
    #endif
#endif
