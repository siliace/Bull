#include <Bull/Network/Unix/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        IpAddress IpAddressImpl::fromSockAddr(const sockaddr* address, NetPort& port)
        {
            switch(address->sa_family)
            {
                case AF_INET:  return fromSockAddr(reinterpret_cast<sockaddr_in*>(address), port);
                case AF_INET6: return fromSockAddr(reinterpret_cast<sockaddr_in6*>(address), port);
            }

            return IpAddress::None;
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in* address, NetPort& port)
        {
            port = ntohs(port);

            return IpAddress(address->sin_addr.s_addr);
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in6* address, NetPort& port)
        {
            return IpAddress::None;
        }

        bool IpAddressImpl::getAddressInfo(const String& hostname, IpAddress& address)
        {
            std::vector<IpAddress> addresses;

            if(getAddressInfo(hostname, addresses))
            {
                address = addresses.front();

                return true;
            }

            return false;
        }

        bool IpAddressImpl::getAddressInfo(const String& hostname, std::vector<IpAddress>& addresses)
        {
            return false;
        }

        IpAddressImpl::SockAddrLength IpAddressImpl::toSockAddr(const IpAddress& ip, NetPort port, void* buffer)
        {
            return 0;
        }
    }
}