#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/SocketLength.hpp>
#include <Bull/Network/Socket/TcpServerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        TcpServerImpl::TcpServerImpl(const std::unique_ptr<prv::SocketImpl>& socket) :
            m_socket(socket)
        {
            /// Nothing
        }

        bool TcpServerImpl::bind(const IpAddressWrapper& address, NetPort port)
        {
            if(m_socket->isValid())
            {
                SockAddrBuffer buffer(address, port);

                return ::bind(m_socket->getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;
            }

            return false;
        }

        bool TcpServerImpl::listen(int backlog)
        {
            if(m_socket->isValid())
            {
                return ::listen(m_socket->getHandler(), backlog) == 0;
            }

            return false;
        }

        SocketHandler TcpServerImpl::accept(IpAddressWrapper& address, NetPort& port)
        {
            SocketHandler client = SocketImpl::getInvalidSocket();

            if(m_socket->isValid())
            {
                sockaddr addr;
                SocketLength length = sizeof(sockaddr);

                client = ::accept(m_socket->getHandler(), &addr, &length);

                if(client != SocketImpl::getInvalidSocket())
                {
                    SockAddrBuffer buffer(addr, length);

                    port = buffer.getPort();
                    address = buffer.getIpAddress();
                }
            }

            return client;
        }
    }
}