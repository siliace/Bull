#include <Bull/Network/Socket/Win32/SocketPollerImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        int SocketPollerImplWin32::poll(std::vector<SocketPollDescriptor>& sockets, int timeout) const
        {
            return WSAPoll(&sockets[0], static_cast<ULONG>(sockets.size()), timeout);
        }
    }
}