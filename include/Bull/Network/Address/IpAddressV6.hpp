#ifndef BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP

#include <array>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    struct BULL_NETWORK_API IpAddressV6 : public IpAddress
    {
        /*! \brief Default constructor
         *
         */
        IpAddressV6();

        /*! \brief Constructor
         *
         * \param bytes Bytes of the IpAddressV6
         *
         */
        explicit IpAddressV6(const ByteArray& bytes);

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
