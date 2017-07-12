#include <Bull/Network/UdpSocket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    UdpSocket::UdpSocket() :
        Socket(Udp)
    {
        /// Nothing
    }

    Socket::State UdpSocket::bind(Socket::Port port, const IpAddress& address)
    {
        if(address == IpAddress::None || address == IpAddress::BroadcastIpv4)
        {
            create(address.getProtocol());

            if(!prv::SocketImpl::bind(getHandler(), address, port))
            {
                return Error;
            }

            return Ready;
        }

        return Error;
    }

    void UdpSocket::unbind()
    {
        close();
    }

    Socket::State UdpSocket::receive(void* data, std::size_t length, std::size_t& received, IpAddress& remoteAddress, Socket::Port& remotePort)
    {
        received      = 0;
        remotePort    = Socket::AnyPort;
        remoteAddress = IpAddress::None;

        create(remoteAddress.getProtocol());

        std::size_t result = prv::SocketImpl::receiveFrom(getHandler(), data, length, remoteAddress, remotePort);

        if(result < 0)
        {
            return Error;
        }

        received = result;

        return Ready;
    }

    Socket::State UdpSocket::send(const IpAddress& remoteAddress, Socket::Port remotePort, const void* data, std::size_t length)
    {
        create(remoteAddress.getProtocol());

        if(length > MaxDatagramSize)
        {
            return Error;
        }

        std::size_t sent = prv::SocketImpl::sendTo(getHandler(), remoteAddress, remotePort, data, length);

        if(sent < 0)
        {
            return prv::SocketImpl::lastError();
        }

        return Ready;
    }
}