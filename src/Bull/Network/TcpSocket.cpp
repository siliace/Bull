#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>

namespace Bull
{
    TcpSocket::TcpSocket() :
        Socket(Tcp)
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
        return false;
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
}