#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Win32/IpAddressImpl.hpp>
#else
    #error Lack of implementation : IpAddress
#endif // defined
