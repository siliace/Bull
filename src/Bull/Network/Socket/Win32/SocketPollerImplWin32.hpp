#ifndef BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
#define BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP

#include <Bull/Network/Socket/SocketPollerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        struct SocketPollerImplWin32 : public SocketPollerImpl
        {
            static constexpr int SocketError = SOCKET_ERROR;

            /*! \brief Poll sockets
             *
             * \param sockets Sockets to poll
             * \param timeout The time before the function fail
             *
             * \return The number of sockets updated during the poll, SocketError if an error occurred
             *
             */
            int poll(std::vector<SocketPollDescriptor>& sockets, int timeout) const;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
