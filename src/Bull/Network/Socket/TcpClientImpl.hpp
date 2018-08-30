#ifndef BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP
#define BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class TcpClientImpl : public NonCopyable
        {
        public:

            /*! \brief Constructor
             *
             * \param socket The SocketImpl to use
             *
             */
            explicit TcpClientImpl(const prv::SocketImpl& socket);

            /*! \brief Connect the TcpClientImpl to a remote host
             *
             * \param address The IpAddress of the remote host
             * \param port    The NetPort of the remote host
             *
             */
            void connect(const IpAddressWrapper& address, NetPort port);

            /*! \brief Send a data buffer the remote host
             *
             * \param data   Data to send
             * \param length The length of data to send
             *
             * \return The amount of bytes sent
             *
             */
            std::size_t send(const void* data, std::size_t length);

            /*! \brief Receive data from the remote host
             *
             * \param data     Data to receive
             * \param length   The length of data to receive
             *
             * \return The amount of bytes received
             *
             */
            std::size_t receive(void* data , std::size_t length);

        private:

            const SocketImpl& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP
