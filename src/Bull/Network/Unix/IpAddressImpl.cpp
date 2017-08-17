#include <Bull/Network/Unix/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        IpAddress IpAddressImpl::fromSockAddr(const sockaddr* address, Socket::Port& port)
        {
            return IpAddress::None;
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in* address, Socket::Port& port)
        {
            return IpAddress::None;
        }

        IpAddress IpAddressImpl::fromSockAddr(const sockaddr_in6* address, Socket::Port& port)
        {
            return IpAddress::None;
        }

        IpAddressImpl::SockAddrLenght IpAddressImpl::toSockAddr(const IpAddress& ip, Socket::Port port, void* buffer)
        {
            return 0;
        }
    }
}