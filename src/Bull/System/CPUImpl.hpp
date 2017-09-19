#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/CPUImpl.hpp>
#else
    #include <Bull/System/Unix/CPUImpl.hpp>
#endif // defined
