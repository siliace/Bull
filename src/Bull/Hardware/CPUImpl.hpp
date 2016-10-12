#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/CPUImpl.hpp>
#else
    #error lack of implementation : CPU
#endif // defined
