#ifndef BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
#define BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP

#include <Bull/Network/Socket/SocketPollerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        struct SocketPollerImplWin32 : public SocketPollerImpl
        {
            /*! \brief Wait until a Socket is ready to read or write
             *
             * \return True if the SocketPollerImplWin32 waited successfully
             *
             */
            bool wait() override;

            /*! \brief Wait until a Socket is ready to read or write
             *
             * \param timeout The time before the function fail
             *
             * \return True if the SocketPollerImplWin32 waited successfully
             *
             */
            bool wait(const Time& timeout) override;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_WIN32_SOCKETPOLLERIMPLWIN32_HPP
