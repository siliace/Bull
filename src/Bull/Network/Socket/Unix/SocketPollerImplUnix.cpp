#include <Bull/Network/Socket/Unix/SocketPollerImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        int SocketPollerImplUnix::poll(std::vector<SocketPollDescriptor>& sockets, int timeout) const
        {
            return ::poll(&sockets[0], sockets.size(), timeout);
        }
    }
}