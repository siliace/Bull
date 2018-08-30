#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/TcpClientImpl.hpp>

namespace Bull
{
    namespace prv
    {
        TcpClientImpl::TcpClientImpl(const prv::SocketImpl& socket) :
            m_socket(socket)
        {
            /// Nothing
        }

        void TcpClientImpl::connect(const IpAddressWrapper& address, NetPort port)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpClientImpl::connect", "Invalid socket"));

            SockAddrBuffer buffer(address, port);

            int ret = ::connect(m_socket.getHandler(), buffer.getSockAddr(), buffer.getLength());

            Expect(ret == 0, Throw(InternalError, "TcpClientImpl::connect", "Failed to connect to the remote host"));
        }

        std::size_t TcpClientImpl::send(const void* data, std::size_t length)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpClientImpl::send", "Invalid socket"));

            int sent = ::send(m_socket.getHandler(), reinterpret_cast<const char*>(data), length, 0);

            Expect(sent >= 0, Throw(InternalError, "TcpClientImpl::send", "Failed to send data to the remote host"));

            return sent;
        }

        std::size_t TcpClientImpl::receive(void* data, std::size_t length)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "TcpClientImpl::receive", "Invalid socket"));

            int received = ::recv(m_socket.getHandler(), reinterpret_cast<char*>(data), length, 0);

            Expect(received >= 0, Throw(InternalError, "TcpClientImpl::receive", "Failed to receive data from the remote host"));

            return received;
        }
    }
}
