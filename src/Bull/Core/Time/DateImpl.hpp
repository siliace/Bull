#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Time/Win32/DateImpl.hpp>
#else
    #include <Bull/Core/Time/Unix/DateImpl.hpp>
#endif
