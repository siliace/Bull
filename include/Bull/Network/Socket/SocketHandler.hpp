#ifndef BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP
#define BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP

#include <Bull/Core/Prerequisites.hpp>

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef Uint64 SocketHandler;
    #else
        typedef int SocketHandler;
    #endif
}

#endif // BULL_NETWORK_SOCKET_SOCKETHANDLER_HPP
