#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Win32/IcmpImpl.hpp>
#else
    #error Lack of implementation : Icmp
#endif