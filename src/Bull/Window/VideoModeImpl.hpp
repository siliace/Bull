#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Window/Win32/VideoModeImpl.hpp>
#else
    #if defined BULL_XLIB
        #include <Bull/Window/Xlib/VideoModeImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Window/XCB/VideoModeImpl.hpp>
    #else
        #error
    #endif
#endif
