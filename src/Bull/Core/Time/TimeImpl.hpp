#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Time/Win32/TimeImpl.hpp>
#else
    #error Lack of implementation : TimeImpl
#endif