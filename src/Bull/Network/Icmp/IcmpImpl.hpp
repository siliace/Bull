#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Icmp/Win32/IcmpImpl.hpp>
#else
    #error Lack of implementation : Icmp
#endif