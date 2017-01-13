#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/CPUImpl.hpp>
#else
    #include <Bull/Hardware/Unix/CPUImpl.hpp>
#endif // defined
