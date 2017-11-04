#ifndef BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP
#define BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP

#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Configuration/Integer.hpp>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef Uint64 SocketHandler;
    #else
        #error Lack of implementation : SocketHandler
    #endif
}

#endif // BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP
