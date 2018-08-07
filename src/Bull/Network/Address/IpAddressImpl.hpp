#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Address/Win32/IpAddressImpl.hpp>
#else
    #include <Bull/Network/Address/Unix/IpAddressImpl.hpp>
#endif