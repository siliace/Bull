#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Win32/CPUImpl.hpp>
#else
    #include <Bull/Core/Hardware/Unix/CPUImpl.hpp>
#endif // defined
