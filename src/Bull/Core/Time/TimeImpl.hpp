#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Time/Win32/TimeImpl.hpp>
#else
    #include <Bull/Core/Time/Unix/TimeImpl.hpp>
#endif