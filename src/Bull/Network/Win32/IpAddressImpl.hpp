#ifndef BULL_IPADDRESSIMPL_HPP
#define BULL_IPADDRESSIMPL_HPP

#include <array>

#include <Bull/Core/Integer.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Win32/SystemSocket.hpp>

namespace Bull
{
    namespace prv
    {
        struct IpAddressImpl
        {
            typedef std::array<Uint8, sizeof(sockaddr_in6)> SocketAddressBuffer;

            /*! \brief Convert a sockaddr to a Bull::IpAddress
             *
             * \param socketAddress The sockaddr to convert
             * \param port          The port of the sockaddr
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSocketAddress(const sockaddr* socketAddress, Uint16& port);

            /*! \brief Convert a sockaddr to a Bull::IpAddress
             *
             * \param socketAddress The sockaddr to convert
             * \param port          The port of the sockaddr
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSocketAddress(const sockaddr_in* socketAddress, Uint16& port);

            /*! \brief Convert a sockaddr to a Bull::IpAddress
             *
             * \param socketAddress The sockaddr to convert
             * \param address       A pointer to the IpAddress to fill
             * \param port          A pointer to the port to fill
             *
             * \return The converted IpAddress
             *
             */
            static IpAddress fromSocketAddress(const sockaddr_in6* socketAddress, Uint16& port);

            /*! \brief Convert a Bull::IpAddress to a sockaddr
             *
             * \param address The IpAddress to convert
             * \param port    The port of the socket address
             * \param buffer  A pointer to the sockaddr to fill
             *
             * \return The new length of the buffer
             *
             */
            static socklen_t toSocketAddress(const IpAddress& address, Uint16 port, void* buffer);
        };
    }
}

#endif // BULL_IPADDRESSIMPL_HPP
