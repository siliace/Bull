#include <Bull/Network/UdpSocket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    UdpSocket::UdpSocket() :
        Socket(SocketType_Udp)
    {
        /// Nothing
    }

    SocketState UdpSocket::bind(Socket::Port port, const IpAddress& address)
    {
        if(address == IpAddress::None || address == IpAddress::BroadcastIpv4)
        {
            create(address.getProtocol());

            if(!prv::SocketImpl::bind(getHandler(), address, port))
            {
                return SocketState_Error;
            }

            return SocketState_Ready;
        }

        return SocketState_Error;
    }

    void UdpSocket::unbind()
    {
        close();
    }

    SocketState UdpSocket::receive(void* data, Index length, Index& received, IpAddress& remoteAddress, Socket::Port& remotePort)
    {
        received      = 0;
        remotePort    = Socket::AnyPort;
        remoteAddress = IpAddress::None;

        create(remoteAddress.getProtocol());

        Index result = prv::SocketImpl::receiveFrom(getHandler(), data, length, remoteAddress, remotePort);

        if(result < 0)
        {
            return SocketState_Error;
        }

        received = result;

        return SocketState_Ready;
    }

    SocketState UdpSocket::send(const void* data, Index length, const IpAddress& remoteAddress, Socket::Port remotePort)
    {
        create(remoteAddress.getProtocol());

        if(length > MaxDatagramSize)
        {
            return SocketState_Error;
        }

        Index sent = prv::SocketImpl::sendTo(getHandler(), data, length, remoteAddress, remotePort);

        if(sent < 0)
        {
            return prv::SocketImpl::lastError();
        }

        return SocketState_Ready;
    }
}