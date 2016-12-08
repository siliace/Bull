#ifndef BULL_IPADDRESSIMPL_HPP
#define BULL_IPADDRESSIMPL_HPP

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    namespace prv
    {
        struct IpAddressImpl
        {
            static IpAddress resolveIpv4(const String& hostname);

            static IpAddress resolveIpv6(const String& hostname);
        };
    }
}

#endif // BULL_IPADDRESSIMPL_HPP
