#include <Bull/Network/Unix/IcmpImpl.hpp>
#include <Bull/Network/Unix/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time IcmpImpl::ping(const IpAddress& host, const Time& timeout)
        {
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