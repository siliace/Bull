#include <Bull/Network/Icmp/Unix/IcmpImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Duration IcmpImpl::ping(const IpAddressV4& address, const Duration& timeout)
        {
            return Duration::Infinite;
        }
    }
}