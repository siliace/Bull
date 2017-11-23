#ifndef BULL_NETWORK_SOCKET_TCPSERVERIMPL_HPP
#define BULL_NETWORK_SOCKET_TCPSERVERIMPL_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class TcpServerImpl : public NonCopyable
        {
        public:

            /*! \brief Constructor
             *
             * \param socket The SocketImpl to use
             *
             */
            TcpServerImpl(const ImplPtr<prv::SocketImpl>& socket);

            /*! \brief Bind the SocketImpl on an IpAddress and a NetPort
             *
             * \param address The IpAddress
             * \param port    The NetPort
             *
             * \return True if the TcpServerImpl has been bound correctly
             *
             */
            bool bind(const IpAddressWrapper& address, NetPort port);

            /*! \brief Start to listen the NetPort
             *
             * \param backlog The number of simultaneous active connection on the TcpServerImpl
             *
             * \return True if the TcpServerImpl is listening the NetPort
             *
             */
            bool listen(int backlog);

            /*! \brief Accept an incoming connection
             *
             * \param address The IpAddress of the client
             * \param port    The NetPort of the client
             *
             * \return The SocketHandler of the accepted client
             *
             */
            SocketHandler accept(IpAddressWrapper& address, NetPort& port);

        private:

            const ImplPtr<prv::SocketImpl>& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_TCPSERVERIMPL_HPP
