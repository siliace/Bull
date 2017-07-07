#include <Bull/Network/Icmp.hpp>
#include <Bull/Network/IcmpImpl.hpp>

namespace Bull
{
    Time Icmp::ping(const IpAddress& host, const Time& timeout)
    {
        return prv::IcmpImpl::ping(host, timeout);
    }

    Time Icmp::averagePing(const IpAddress& host, unsigned int count, const Time& timeout)
    {
        Time total;

        for(unsigned int i = 0; i < count; i++)
        {
            total += ping(host, timeout);
        }

        return total / count;
    }
}