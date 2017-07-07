#include <Bull/Network/Win32/IcmpImpl.hpp>
#include <Bull/Network/Win32/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time IcmpImpl::ping(const IpAddress& host, const Time& timeout)
        {
            switch(host.getProtocol())
            {
                case NetProtocol_IpV4:
                {
                    return ping(host.toUint32(), timeout);
                }

                case NetProtocol_IpV6:
                {
                    IpAddressImpl::SockAddrBuffer sockAddr;
                    IpAddressImpl::SockAddrLenght length = IpAddressImpl::toSockAddr(host, Socket::AnyPort, &sockAddr[0]);

                    if(length > 0)
                    {
                        return ping(reinterpret_cast<const sockaddr_in6*>(&sockAddr[0]), timeout);
                    }
                }
            }

            return Time::Zero;
        }

        Time IcmpImpl::ping(Uint32 host, const Time& timeout)
        {
            return Time::Zero;
        }

        Time IcmpImpl::ping(const sockaddr_in6* host, const Time& timeout)
        {
            return Time::Zero;
        }
    }
}