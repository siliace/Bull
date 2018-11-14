#ifndef BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
#define BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP

#include <Bull/Network/Socket/SocketPollerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketPollerImplWin32 : public SocketPollerImpl
        {
        public:

            static constexpr int SocketError = SOCKET_ERROR;

        public:

            /*! \brief Poll sockets
             *
             * \param sockets Sockets to poll
             * \param timeout The time before the function fail
             *
             * \return The number of sockets updated during the poll
             *
             */
            int poll(std::vector<SocketPollDescriptor>& sockets, int timeout) const override;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
