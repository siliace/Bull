#include <Bull/Network/Icmp/Icmp.hpp>
#include <Bull/Network/Icmp/IcmpImpl.hpp>

namespace Bull
{
    Time Icmp::ping(const IpAddressV4& address, const Time& timeout)
    {
        return prv::IcmpImpl::ping(address, timeout);
    }
}