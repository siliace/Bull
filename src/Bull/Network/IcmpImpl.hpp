#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Win32/IcmpImpl.hpp>
#else
    #include <Bull/Network/Unix/IcmpImpl.hpp>
#endif