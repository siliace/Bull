#ifndef BULL_NETWORK_WIN32_ICMPIMPL_HPP
#define BULL_NETWORK_WIN32_ICMPIMPL_HPP

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iphlpapi.h>
#include <icmpapi.h>

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    namespace prv
    {
        class IcmpImpl
        {
        public:

            /*! \brief
             *
             * \param host
             * \param timeout
             *
             * \return
             *
             */
            static Time ping(const IpAddress& host, const Time& timeout);

        private:

            /*! \brief
             *
             * \param host
             * \param timeout
             *
             * \return
             *
             */
            static Time ping(Uint32 host, const Time& timeout);

            /*! \brief
             *
             * \param host
             * \param timeout
             *
             * \return
             *
             */
            static Time ping(const sockaddr_in6* host, const Time& timeout);
        };
    }
}

#endif // BULL_NETWORK_WIN32_ICMPIMPL_HPP
