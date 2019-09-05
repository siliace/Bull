#ifndef BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP

#include <array>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    struct BULL_NETWORK_API IpAddressV4 : public IpAddress
    {
        static IpAddressV4 Any;
        static IpAddressV4 None;
        static IpAddressV4 Loopback;
        static IpAddressV4 Broadcast;

        /** \brief Default constructor
         *
         */
        IpAddressV4();

        /** \brief Constructor
         *
         * \param address
         *
         */
        explicit IpAddressV4(Uint32 address);

        /** \brief Constructor
         *
         * \param a The first byte of the IpAddressV4
         * \param b The second byte of the IpAddressV4
         * \param c The third byte of the IpAddressV4
         * \param d The forth byte of the IpAddressV4
         *
         */
        IpAddressV4(Uint8 a, Uint8 b, Uint8 c, Uint8 d);

        /** \brief Convert the IpAddressV4 to an Uint32
         *
         * \return The IpAddressV4 as a Uint32
         *
         */
        Uint32 toInt() const;

        /** \brief Convert the IpAddressV4 to a std::string
         *
         * \return The IpAddressV4 as a std::string
         *
         */
        std::string toString() const override;

        /** \brief Get the NetProtocol used by the IpAddress
         *
         * \return The NetProtocol
         *
         */
        NetProtocol getProtocol() const override;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP
