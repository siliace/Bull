#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Utility/Window/Win32/VideoModeImpl.hpp>
#else
    #include <Bull/Window/X11/VideoModeImpl.hpp>
#endif
