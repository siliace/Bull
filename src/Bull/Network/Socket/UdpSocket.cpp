#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>
#include <Bull/Network/Socket/SocketLength.hpp>
#include <Bull/Network/Socket/UdpSocket.hpp>

namespace Bull
{
    UdpSocket::UdpSocket() :
        Socket(SocketType_Udp)
    {
        /// Nothing
    }

    UdpSocket::~UdpSocket()
    {
        unbind();
    }

    void UdpSocket::bind(NetPort port, const IpAddress& host)
    {
        Expect(host.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        create(host.getProtocol());

        prv::SockAddrBuffer buffer(host, port);

        int ret = ::bind(getHandler(), buffer.getSockAddr(), buffer.getLength()) == 0;

        Expect(ret == 0, Throw(InternalError, "UdpSocketImpl::bind", "Failed to bind the socket"));
    }

    bool UdpSocket::isBound() const
    {
        return getHandler() != prv::SocketImpl::getInvalidSocket();
    }

    void UdpSocket::unbind()
    {
        close();
    }

    std::size_t UdpSocket::sendTo(const IpAddress& address, NetPort port, const void* data, std::size_t length) const
    {
        Expect(data && length, Throw(InvalidParameter, "TcpClient::send", "Invalid buffer"));
        Expect(isBound(), Throw(LogicError, "UdpSocket::sendTo", "The UdpSocket is not bound"));
        Expect(address.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        prv::SockAddrBuffer buffer(address, port);

        int sent = ::sendto(getHandler(), reinterpret_cast<const char*>(data), length, 0, buffer.getSockAddr(), buffer.getLength()) == 0;

        Expect(sent >= 0, Throw(InternalError, "UdpSocketImpl::sendTo", "Failed to send data to the remote host"));

        return sent;
    }

    Datagram UdpSocket::receiveFrom() const
    {
        return receiveFrom(getPendingLength());
    }

    Datagram UdpSocket::receiveFrom(std::size_t length) const
    {
        Expect(length, Throw(InvalidParameter, "TcpClient::send", "Invalid length"));
        Expect(isBound(), Throw(LogicError, "UdpSocket::sendTo", "The UdpSocket is not bound"));

        sockaddr addr;
        Datagram datagram;
        prv::SocketLength sockLength = sizeof(sockaddr);

        datagram.bytes.create(length);

        int received = ::recvfrom(getHandler(), reinterpret_cast<char*>(&datagram.bytes[0]), length, 0, &addr, &sockLength);

        Expect(received >= 0, Throw(InternalError, "UdpSocketImpl::sendTo", "Failed to receive data to from remote host"));

        datagram.bytes.resize(received);

        prv::SockAddrBuffer buffer(addr, sockLength);

        datagram.port    = buffer.getPort();
        datagram.address = buffer.getIpAddress();

        return datagram;
    }
}