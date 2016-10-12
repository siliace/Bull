#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Window/Win32/VideoModeImpl.hpp>
#else
    #error Lack of implementation : VideoMode
#endif

