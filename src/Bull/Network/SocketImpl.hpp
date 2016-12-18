#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Win32/SocketImpl.hpp>
#else
    #error Lack of implementation : Socket
#endif // defined
