#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Icmp/Win32/IcmpImpl.hpp>
#else
    #include <Bull/Network/Icmp/Unix/IcmpImpl.hpp>
#endif