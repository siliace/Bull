#ifndef BULL_NETWORK_SOCKET_SOCKETLENGTH_HPP
#define BULL_NETWORK_SOCKET_SOCKETLENGTH_HPP

#include <Bull/Core/Configuration/OS.hpp>

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef int SocketLength;
        #else
            typedef socklen_t SocketLength;
        #endif
    }
}

#endif // BULL_NETWORK_SOCKET_SOCKETLENGTH_HPP
