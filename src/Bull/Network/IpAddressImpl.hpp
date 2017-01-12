#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Win32/IpAddressImpl.hpp>
#else
    #include <Bull/Network/Unix/IpAddressImpl.hpp>
#endif
