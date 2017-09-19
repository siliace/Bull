#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/RAMImpl.hpp>
#else
    #include <Bull/System/Unix/RAMImpl.hpp>
#endif
