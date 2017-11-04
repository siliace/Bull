#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/TcpClientImpl.hpp>

namespace Bull
{
    namespace prv
    {
        TcpClientImpl::TcpClientImpl(const std::unique_ptr<prv::SocketImpl>& socket) :
            m_socket(socket)
        {
            /// Nothing
        }

        bool TcpClientImpl::connect(const IpAddressWrapper& address, NetPort port)
        {
            if(m_socket->isValid())
            {
                SockAddrBuffer buffer(address, port);

                return ::connect(m_socket->getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;
            }

            return false;
        }

        bool TcpClientImpl::send(const void* data, std::size_t length, std::size_t& sent)
        {
            if(m_socket->isValid())
            {
                sent = ::send(m_socket->getHandler(), reinterpret_cast<const char*>(data), length, 0);

                if(sent >= 0)
                {
                    return true;
                }
            }

            sent = 0;

            return false;
        }

        bool TcpClientImpl::reveive(void* data, std::size_t length, std::size_t& received)
        {
            if(m_socket->isValid())
            {
                received = ::recv(m_socket->getHandler(), reinterpret_cast<char*>(data), length, 0);

                if(received >= 0)
                {
                    return true;
                }
            }

            received = 0;

            return false;
        }
    }
}
