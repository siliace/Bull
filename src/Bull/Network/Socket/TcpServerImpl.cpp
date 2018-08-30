#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/SocketLength.hpp>
#include <Bull/Network/Socket/TcpServerImpl.hpp>

namespace Bull
{
    namespace prv
    {
        TcpServerImpl::TcpServerImpl(const prv::SocketImpl& socket) :
                m_socket(socket)
        {
            /// Nothing
        }

        void TcpServerImpl::bind(const IpAddressWrapper& address, NetPort port)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpServerImpl::bind", "Invalid socket"));

            SockAddrBuffer buffer(address, port);

            int ret = ::bind(m_socket.getHandler(), buffer.getSockAddr(), buffer.getLength());

            Expect(ret == 0, Throw(InternalError, "TcpServerImpl::bind", "Failed to bind the socket"));
        }

        void TcpServerImpl::listen(int backlog)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpServerImpl::listen", "Invalid socket"));

            int ret = ::listen(m_socket.getHandler(), backlog);

            Expect(ret == 0, Throw(InternalError, "TcpServerImpl::listen", "Failed to listen the port"));
        }

        SocketHandler TcpServerImpl::accept(IpAddressWrapper& address, NetPort& port)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpServerImpl::accept", "Invalid socket"));

            sockaddr addr;
            SocketLength length = sizeof(sockaddr);

            SocketHandler client = ::accept(m_socket.getHandler(), &addr, &length);

            Expect(client != SocketImpl::getInvalidSocket(), Throw(InternalError, "TcpServerImpl::accept", "Failed to accept client"));

            SockAddrBuffer buffer(addr, length);

            port = buffer.getPort();
            address = buffer.getIpAddress();

            return client;
        }
    }
}