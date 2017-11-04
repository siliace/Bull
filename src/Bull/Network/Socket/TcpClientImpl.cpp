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

        bool TcpClientImpl::connect(const IpAddress& address, NetPort port)
        {
            if(m_socket->isValid())
            {
                SockAddrBuffer buffer(address, port);

                return ::connect(m_socket->getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;
            }

            return false;
        }
    }
}
