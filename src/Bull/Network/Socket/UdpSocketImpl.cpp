#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/SocketLength.hpp>
#include <Bull/Network/Socket/UdpSocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        UdpSocketImpl::UdpSocketImpl(const SocketImpl& socket) :
            m_socket(socket)
        {
            /// Nothing
        }

        void UdpSocketImpl::bind(NetPort port, const IpAddressWrapper& address)
        {
            Expect(m_socket.isValid(), Throw(LogicError, "UdpSocketImpl::bind", "Invalid socket"));

            SockAddrBuffer buffer(address, port);

            int ret = ::bind(m_socket.getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;

            Expect(ret == 0, Throw(InternalError, "UdpSocketImpl::bind", "Failed to bind the socket"));
        }

        std::size_t UdpSocketImpl::sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length) const
        {
            Expect(m_socket.isValid(), Throw(LogicError, "UdpSocketImpl::sendTo", "Invalid socket"));

            SockAddrBuffer buffer(address, port);

            int sent = ::sendto(m_socket.getHandler(), reinterpret_cast<const char*>(data), length, 0, buffer.getSockAddr(), buffer.getLength()) == 0;

            Expect(sent >= 0, Throw(InternalError, "UdpSocketImpl::sendTo", "Failed to send data to the remote host"));

            return sent;
        }

        std::size_t UdpSocketImpl::receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length) const
        {
            Expect(m_socket.isValid(), Throw(LogicError, "UdpSocketImpl::bind", "Invalid socket"));

            sockaddr addr;
            SocketLength sockLength = sizeof(sockaddr);

            int received = ::recvfrom(m_socket.getHandler(), reinterpret_cast<char*>(data), length, 0, &addr, &sockLength);

            Expect(received >= 0, Throw(InternalError, "UdpSocketImpl::sendTo", "Failed to receive data to from remote host"));

            SockAddrBuffer buffer(addr, sockLength);

            port    = buffer.getPort();
            address = buffer.getIpAddress();

            return received;
        }
    }
}