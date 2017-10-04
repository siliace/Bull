#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Win32/RAMImpl.hpp>
#else
    #include <Bull/Core/Hardware/Unix/RAMImpl.hpp>
#endif
