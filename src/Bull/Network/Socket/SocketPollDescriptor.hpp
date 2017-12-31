#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLDESCRIPTOR_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLDESCRIPTOR_HPP

#include <Bull/Core/Configuration/OS.hpp>

#include <Bull/Network/Socket/SocketHeader.hpp>

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef WSAPOLLFD SocketPollDescriptor;
        #else
            typedef struct pollfd SocketPollDescriptor;
        #endif
    }
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLDESCRIPTOR_HPP
