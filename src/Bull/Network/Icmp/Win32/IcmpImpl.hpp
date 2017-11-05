#ifndef BULL_NETWORK_ICMP_WIN32_ICMPIMPL_HPP
#define BULL_NETWORK_ICMP_WIN32_ICMPIMPL_HPP

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>

namespace Bull
{
    namespace prv
    {
        class IcmpImpl
        {
        public:

            /*! \brief Send a ping
             *
             * \param address The IpAddress to ping
             * \param timeout The time before the function fail
             *
             * \return The ping duration
             *
             */
            static Time ping(const IpAddressV4& address, const Time& timeout);
        };
    }
}

#endif // BULL_NETWORK_ICMP_WIN32_ICMPIMPL_HPP
