#include <cstring>

#include <Bull/Network/Unix/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        IpAddress IpAddressImpl::fromSocketAddress(const sockaddr* socketAddress, Uint16& port)
        {
            switch(socketAddress->sa_family)
            {
                case AF_INET:  return fromSocketAddress(reinterpret_cast<const sockaddr_in*>(socketAddress), port);
                case AF_INET6: return fromSocketAddress(reinterpret_cast<const sockaddr_in6*>(socketAddress), port);
            }

            return IpAddress::None;
        }

        IpAddress IpAddressImpl::fromSocketAddress(const sockaddr_in* socketAddress, Uint16& port)
        {
            IpAddress::V4 ipv4;

            ipv4[0] = (socketAddress->sin_addr.s_addr & 0xff000000) >> 24;
            ipv4[1] = (socketAddress->sin_addr.s_addr & 0x00ff0000) >> 16;
            ipv4[2] = (socketAddress->sin_addr.s_addr & 0x0000ff00) >> 8;
            ipv4[3] = (socketAddress->sin_addr.s_addr & 0x000000ff) >> 0;

            port = ntohs(socketAddress->sin_port);

            return IpAddress(ipv4);
        }

        IpAddress IpAddressImpl::fromSocketAddress(const sockaddr_in6* socketAddress, Uint16& port)
        {
            IpAddress::V6 ipv6;

            for(Uint16 i = 0; i < ipv6.size(); i++)
            {
                ipv6[i] = ntohs(socketAddress->sin6_addr.s6_addr16[i]);
            }

            port = ntohs(socketAddress->sin6_port);

            return IpAddress(ipv6);
        }

        socklen_t IpAddressImpl::toSocketAddress(const IpAddress& address, Uint16 port, void* buffer)
        {
            switch(address.getProtocol())
            {
                case NetProtocol::Ipv4:
                {
                    sockaddr_in* socketAddress = reinterpret_cast<sockaddr_in*>(buffer);

                    std::memset(socketAddress, 0, sizeof(sockaddr_in6));

                    socketAddress->sin_family      = AF_INET;
                    socketAddress->sin_port        = htons(port);
                    socketAddress->sin_addr.s_addr = htonl(address.toInteger());

                    return sizeof(sockaddr_in);
                }

                case NetProtocol::Ipv6:
                {
                    IpAddress::V6 raw = address.toV6();
                    sockaddr_in6* socketAddress = reinterpret_cast<sockaddr_in6*>(buffer);

                    std::memset(socketAddress, 0, sizeof(sockaddr_in6));

                    socketAddress->sin6_family = AF_INET6;
                    socketAddress->sin6_port   = htons(port);

                    for(Uint16 i = 0; i < raw.size(); i++)
                    {
                        socketAddress->sin6_addr.s6_addr16[i] = htons(raw[i]);
                    }

                    return sizeof(sockaddr_in6);
                }
            }

            return 0;
        }
    }
}
