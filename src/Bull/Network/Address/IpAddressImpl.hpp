#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Address/Win32/IpAddressImpl.hpp>
#else
    #error Lack of implementation : IpAddres
#endif