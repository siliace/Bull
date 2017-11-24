#ifndef BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    struct BULL_NETWORK_API IpAddressV6 : public IpAddress
    {
        /*! \brief Default constructor
         *
         */
        IpAddressV6();

        /*! \brief Convert the IpAddressV6 to a String
         *
         * \return The IpAddressV6 as a String
         *
         */
        String toString() const override;

        /*! \brief Get the NetProtocol used by the IpAddressV6
         *
         * \return The NetProtocol
         *
         */
        NetProtocol getProtocol() const override;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP
