#ifndef BULL_NETWORK_UNIX_IPADDRESSIMPL_HPP
#define BULL_NETWORK_UNIX_IPADDRESSIMPL_HPP

#include <array>

#include <netinet/in.h>

#include <Bull/Core/System/Integer.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>

namespace Bull
{
    namespace prv
    {
        struct IpAddressImpl
        {
            using SockAddrLenght = socklen_t;
            using SockAddrBuffer = std::array<Uint8, sizeof(sockaddr_in6)>;

            /*! \brief Convert a sockaddr to an IpAddress
             *
             * \param address The sockaddr to convert
             * \param port    The port used by the sockaddr
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSockAddr(const sockaddr* address, Socket::Port& port);

            /*! \brief Convert a sockaddr_in to an IpAddress
             *
             * \param address The sockaddr_in to convert
             * \param port    The port used by the sockaddr_in
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSockAddr(const sockaddr_in* address, Socket::Port& port);

            /*! \brief Convert a sockaddr_in6 to an IpAddress
             *
             * \param address The sockaddr_in6 to convert
             * \param port    The port used by the sockaddr_in6
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSockAddr(const sockaddr_in6* address, Socket::Port& port);

            /*! \brief Convert an IpAddress to a sockaddr
             *
             * \param ip     The IpAddress to use in the sockaddr
             * \param port   The port to use in the sockaddr
             * \param buffer The buffer to fill with the sockaddr
             *
             * \return The length of the converted sockaddr
             *
             */
            static SockAddrLenght toSockAddr(const IpAddress& ip, Socket::Port port, void* buffer);
        };
    }
}

#endif // BULL_NETWORK_UNIX_IPADDRESSIMPL_HPP
