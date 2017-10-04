#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Win32/VideoModeImpl.hpp>
#else
    #if defined BULL_XLIB
        #include <Bull/Core/Window/Xlib/VideoModeImpl.hpp>
    #elif defined BULL_XCB
        #include <Bull/Window/XCB/VideoModeImpl.hpp>
    #else
        #error
    #endif
#endif
