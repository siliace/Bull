#ifndef BULL_NETWORK_SOCKET_UNIX_SOCKETPOLLERIMPLUNIX_HPP
#define BULL_NETWORK_SOCKET_UNIX_SOCKETPOLLERIMPLUNIX_HPP

#include <Bull/Network/Socket/SocketPollerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketPollerImplUnix : public SocketPollerImpl
        {
        public:

            static constexpr int SocketError = -1;

        public:

            /** \brief Poll sockets
             *
             * \param sockets Sockets to poll
             * \param timeout The time before the function fail
             *
             * \return The number of sockets updated during the poll, SocketError if an error occurred
             *
             */
            int poll(std::vector<SocketPollDescriptor>& sockets, int timeout) const override;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_UNIX_SOCKETPOLLERIMPLUNIX_HPP
