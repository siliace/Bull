#ifndef BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddressV4 : public IpAddress
    {
    public:

        static IpAddressV4 Any;
        static IpAddressV4 None;
        static IpAddressV4 Loopback;
        static IpAddressV4 Broadcast;

    public:

        /*! \brief Default constructor
         *
         */
        IpAddressV4();

        /*! \brief Constructor
         *
         * \param address
         *
         */
        explicit IpAddressV4(Uint32 address);

        /*! \brief Constructor
         *
         * \param a The first byte of the IpAddressV4
         * \param b The second byte of the IpAddressV4
         * \param c The thrid byte of the IpAddressV4
         * \param d The forth byte of the IpAddressV4
         *
         */
        IpAddressV4(Uint8 a, Uint8 b, Uint8 c, Uint8 d);

        /*! \brief Convert the IpAddressV4 to an Uint32
         *
         * \return The IpAddressV4 as a Uint32
         *
         */
        Uint32 toInt() const;

        /*! \brief Convert the IpAddressV4 to a String
         *
         * \return The IpAddressV4 as a String
         *
         */
        String toString() const override;

        /*! \brief Get the NetProtocol used by the IpAddress
         *
         * \return The NetProtocol
         *
         */
        NetProtocol getProtocol() const override;

    private:

        ByteArray m_bytes;
        bool      m_valid;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESSV4_HPP
