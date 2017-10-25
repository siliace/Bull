#ifndef BULL_NETWORK_SOCKETSTATE_HPP
#define BULL_NETWORK_SOCKETSTATE_HPP

namespace Bull
{
    enum SocketState
    {
        SocketState_Ready,
        SocketState_NotReady,
        SocketState_Partial,
        SocketState_Disconnected,
        SocketState_ConnectionRefused,
        SocketState_Error,
    };
}

#endif // BULL_NETWORK_SOCKETSTATE_HPP
