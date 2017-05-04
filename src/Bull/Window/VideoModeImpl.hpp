#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Window/Win32/VideoModeImpl.hpp>
#else
    #include <Bull/Window/X11/VideoModeImpl.hpp>
#endif
