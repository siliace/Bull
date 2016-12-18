#include <Bull/Network/Win32/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void IpAddressImpl::fromSocketAddress(const sockaddr* socketAddress, IpAddress* address, Uint16* port)
        {
            switch(socketAddress->sa_family)
            {
                case AF_INET:  fromSocketAddress(reinterpret_cast<const sockaddr_in*>(&socketAddress), address, port);
                case AF_INET6: fromSocketAddress(reinterpret_cast<const sockaddr_in6*>(&socketAddress), address, port);
            }
        }

        void IpAddressImpl::fromSocketAddress(const sockaddr_in* socketAddress, IpAddress* address, Uint16* port)
        {
            IpAddress::V4 ipv4;

            ipv4[0] = ntohs(socketAddress->sin_addr.S_un.S_un_b.s_b1);
            ipv4[1] = ntohs(socketAddress->sin_addr.S_un.S_un_b.s_b2);
            ipv4[2] = ntohs(socketAddress->sin_addr.S_un.S_un_b.s_b3);
            ipv4[3] = ntohs(socketAddress->sin_addr.S_un.S_un_b.s_b4);

            (*address) = IpAddress(ipv4);
            (*port)    = ntohs(socketAddress->sin_port);
        }

        void IpAddressImpl::fromSocketAddress(const sockaddr_in6* socketAddress, IpAddress* address, Uint16* port)
        {
            IpAddress::V6 ipv6;

            for(Uint16 i = 0; i < ipv6.size(); i++)
            {
                ipv6[i] = ntohs(socketAddress->sin6_addr.u.Word[i]);
            }

            (*address) = IpAddress(ipv6);
            (*port)    = ntohs(socketAddress->sin6_port);
        }

        socklen_t IpAddressImpl::toSocketAddress(const IpAddress& address, Uint16 port, void* buffer)
        {
            switch(address.getProtocol())
            {
                case NetProtocol::Ipv4:
                {
                    IpAddress::V4 raw = address.toV4();
                    sockaddr_in* socketAddress = reinterpret_cast<sockaddr_in*>(buffer);

                    ZeroMemory(socketAddress, sizeof(sockaddr_in));

                    socketAddress->sin_family      = AF_INET;
                    socketAddress->sin_port        = htons(port);
                    socketAddress->sin_addr.s_addr = htonl(address.toInteger());

                    return sizeof(sockaddr_in);
                }
                break;

                case NetProtocol::Ipv6:
                {
                    IpAddress::V6 raw = address.toV6();
                    sockaddr_in6* socketAddress = reinterpret_cast<sockaddr_in6*>(buffer);

                    ZeroMemory(socketAddress, sizeof(sockaddr_in6));

                    socketAddress->sin6_family = AF_INET6;
                    socketAddress->sin6_port   = htons(port);

                    for(Uint16 i = 0; i < raw.size(); i++)
                    {
                        socketAddress->sin6_addr.u.Word[i] = htons(raw[i]);
                    }

                    return sizeof(sockaddr_in6);
                }
                break;
            }

            return 0;
        }
    }
}
