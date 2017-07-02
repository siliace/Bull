#include <Bull/Network/Win32/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        IpAddress IpAddressImpl::fromSockAddr(const sockaddr* address, Socket::Port& port)
        {
            switch(address->sa_family)
            {
                case AF_INET:  return fromSockAddr(reinterpret_cast<const sockaddr_in*>(address), port);
                case AF_INET6: return fromSockAddr(reinterpret_cast<const sockaddr_in6*>(address), port);
            }

            return IpAddress::None;
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in* address, Socket::Port& port)
        {
            port = ntohs(address->sin_port);

            return IpAddress(address->sin_addr.s_net, address->sin_addr.s_host, address->sin_addr.s_lh, address->sin_addr.s_impno);
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in6* address, Socket::Port& port)
        {

        }

        IpAddressImpl::SockAddrLenght IpAddressImpl::toSockAddr(const IpAddress& ip, Socket::Port port, void* buffer)
        {
            if(ip.isValid())
            {
                switch(ip.getProtocol())
                {
                    case NetProtocol_IpV4:
                    {
                        sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(buffer);
                        ZeroMemory(addr, sizeof(sockaddr_in));
                        addr->sin_port        = htons(port);
                        addr->sin_family      = AF_INET;
                        addr->sin_addr.s_addr = ip.toUint32();

                        return sizeof(sockaddr_in);
                    }
                }
            }
        }
    }
}