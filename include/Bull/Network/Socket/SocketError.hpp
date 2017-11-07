#ifndef BULL_NETWORK_SOCKET_SOCKETERROR_HPP
#define BULL_NETWORK_SOCKET_SOCKETERROR_HPP

namespace Bull
{
    enum SocketError
    {
        SocketError_Ok,
        SocketError_Error,
        SocketError_Timeout,
        SocketError_Disconnected,
        SocketError_NetworkFailed,
        SocketError_ConnectionRefused,
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKETERROR_HPP
