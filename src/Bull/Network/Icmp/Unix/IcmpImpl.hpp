#ifndef BULL_NETWORK_ICMP_UNIX_ICMPIMPL_HPP
#define BULL_NETWORK_ICMP_UNIX_ICMPIMPL_HPP

#include <Bull/Core/Time/Duration.hpp>

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
            static Duration ping(const IpAddressV4& address, const Duration& timeout);
        };
    }
}

#endif // BULL_NETWORK_ICMP_UNIX_ICMPIMPL_HPP
