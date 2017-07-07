#ifndef BULL_NETWORK_ICMP_HPP
#define BULL_NETWORK_ICMP_HPP

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    struct BULL_NETWORK_API Icmp
    {
        /*! \brief
         *
         * \param host
         * \param timeout
         *
         * \return
         *
         */
        static Time ping(const IpAddress& host, const Time& timeout = Time::seconds(1.f));

        /*! \brief
         *
         * \param host
         * \param count
         * \param timeout
         *
         * \return
         *
         */
        static Time averagePing(const IpAddress& host, unsigned int count = 50, const Time& timeout = Time::seconds(1.f));
    };
}

#endif // BULL_NETWORK_ICMP_HPP
