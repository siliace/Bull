#ifndef BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP
#define BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP

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
            TcpClientImpl(const std::unique_ptr<prv::SocketImpl>& socket);

            /*! \brief Connect the TcpClientImpl to a remote host
             *
             * \param address The IpAddress of the remote host
             * \param port    The NetPort of the remote host
             *
             * \return True if the TcpClientImpl is connected
             *
             */
            bool connect(const IpAddressWrapper& address, NetPort port);

            bool send(const void* data, std::size_t length, std::size_t& sent);

            bool reveive(void* data , std::size_t length, std::size_t& received);

        private:

            const std::unique_ptr<SocketImpl>& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_TCPCLIENTIMPL_HPP
