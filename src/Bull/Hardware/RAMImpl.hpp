#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/RAMImpl.hpp>
#else
    #include <Bull/Hardware/Unix/RAMImpl.hpp>
#endif
