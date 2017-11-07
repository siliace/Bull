#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP

namespace Bull
{
    enum SocketPollerEvent
    {
        SocketPollerEvent_Read  = 0x2,
        SocketPollerEvent_Write = 0x4,
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP
