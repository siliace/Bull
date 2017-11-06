#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP

namespace Bull
{
    enum SocketPollerEvent
    {
        SocketPollerEvent_Read,
        SocketPollerEvent_Write,
        SocketPollerEvent_All,
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLEREVENT_HPP
