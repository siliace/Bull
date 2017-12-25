#include <Bull/Network/Icmp/Icmp.hpp>
#include <Bull/Network/Icmp/IcmpImpl.hpp>

namespace Bull
{
    Duration Icmp::ping(const IpAddressV4& address, const Duration& timeout)
    {
        return prv::IcmpImpl::ping(address, timeout);
    }
}