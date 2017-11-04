#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Socket/Win32/SocketHeader.hpp>
#else
    #error Lack of implementation : SocketHeader
#endif