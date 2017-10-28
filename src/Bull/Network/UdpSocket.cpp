#include <Bull/Network/UdpSocket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    UdpSocket::UdpSocket() :
        Socket(SocketType_Udp)
    {
        /// Nothing
    }

    SocketState UdpSocket::bind(NetPort port, const IpAddress& address)
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

    SocketState UdpSocket::receive(void* data, Index length, Index& received, IpAddress& remoteAddress, NetPort& remotePort)
    {
        received      = 0;
        remotePort    = NetPort_Any;
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

    SocketState UdpSocket::send(const void* data, Index length, const IpAddress& remoteAddress, NetPort remotePort)
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