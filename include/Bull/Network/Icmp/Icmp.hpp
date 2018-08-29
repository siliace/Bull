#ifndef BULL_NETWORK_ICMP_ICMP_HPP
#define BULL_NETWORK_ICMP_ICMP_HPP

#include <Bull/Core/Time/Duration.hpp>

#include <Bull/Network/Address/IpAddressV4.hpp>

namespace Bull
{
    struct BULL_NETWORK_API Icmp
    {
        /*! \brief Send a ping
         *
         * \param address The IpAddress to ping
         * \param timeout The time before the function fail
         *
         * \return The ping duration
         *
         */
        static Duration ping(const IpAddressV4& address, const Duration& timeout = Duration::seconds(1.f));
    };
}

#endif // BULL_NETWORK_ICMP_ICMP_HPP
