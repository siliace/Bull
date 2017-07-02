#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>

namespace Bull
{
    TcpSocket::TcpSocket() :
        Socket(Tcp),
        m_remotePort(AnyPort),
        m_remoteAddress(IpAddress::None)
    {
        /// Nothing
    }

    Socket::State TcpSocket::connect(const IpAddress& address, Port port)
    {
        return Disconnected;
    }

    Socket::State TcpSocket::connect(const IpAddress& address, Port port, const Time& timeout)
    {
        return Disconnected;
    }

    bool TcpSocket::isConnected() const
    {
        return m_remoteAddress.isValid() && m_remotePort != AnyPort;
    }

    void TcpSocket::disconnect()
    {
        close();
    }

    Socket::State TcpSocket::send(const void* data, std::size_t length, std::size_t* sent)
    {
        return Disconnected;
    }

    Socket::State TcpSocket::receive(void* data, std::size_t length)
    {
        return Disconnected;
    }

    void TcpSocket::reset(SocketHandler handler, const IpAddress& address, Socket::Port port)
    {
        Socket::reset(handler);

        m_remotePort    = port;
        m_remoteAddress = address;
    }
}