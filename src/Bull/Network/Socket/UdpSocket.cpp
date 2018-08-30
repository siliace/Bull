#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Network/Socket/UdpSocket.hpp>
#include <Bull/Network/Socket/UdpSocketImpl.hpp>

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

    void UdpSocket::bind(NetPort port, const IpAddressWrapper& host)
    {
        Expect(host.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        create(host.getProtocol());

        m_impl = std::make_unique<prv::UdpSocketImpl>(getImpl());

        m_impl->bind(port, host);
    }

    bool UdpSocket::isBound() const
    {
        return m_impl != nullptr;
    }

    void UdpSocket::unbind()
    {
        close();
        m_impl.reset();
    }

    std::size_t UdpSocket::sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length) const
    {
        Expect(data && length, Throw(InvalidParameter, "TcpClient::send", "Invalid buffer"));
        Expect(isBound(), Throw(LogicError, "UdpSocket::sendTo", "The UdpSocket is not bound"));
        Expect(address.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        return m_impl->sendTo(address, port, data, length);
    }

    std::size_t UdpSocket::receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length) const
    {
        Expect(data && length, Throw(InvalidParameter, "TcpClient::send", "Invalid buffer"));
        Expect(isBound(), Throw(LogicError, "UdpSocket::sendTo", "The UdpSocket is not bound"));

        return m_impl->receiveFrom(address, port, data, length);
    }
}