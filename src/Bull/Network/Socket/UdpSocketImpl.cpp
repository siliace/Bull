#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/UdpSocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        UdpSocketImpl::UdpSocketImpl(const ImplPtr<SocketImpl>& socket) :
            m_socket(socket)
        {
            /// Nothing
        }

        bool UdpSocketImpl::bind(NetPort port, const IpAddressWrapper& address)
        {
            if(m_socket->isValid())
            {
                SockAddrBuffer buffer(address, port);

                return ::bind(m_socket->getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;
            }

            return false;
        }

        bool UdpSocketImpl::sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const
        {
            if(m_socket->isValid())
            {
                SockAddrBuffer buffer(address, port);

                return ::sendto(m_socket->getHandler(), reinterpret_cast<const char*>(data), length, 0, buffer.getSockAddr(), buffer.getLength()) == 0;
            }

            sent = 0;

            return false;
        }

        bool UdpSocketImpl::receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const
        {
            if(m_socket->isValid())
            {
                sockaddr addr;
                int sockLength = sizeof(sockaddr);

                received = ::recvfrom(m_socket->getHandler(), reinterpret_cast<char*>(data), length, 0, &addr, &sockLength);

                if(received >= 0)
                {
                    SockAddrBuffer buffer(addr, sockLength);

                    port    = buffer.getPort();
                    address = buffer.getIpAddress();

                    return true;
                }
            }

            received = 0;

            return false;
        }
    }
}