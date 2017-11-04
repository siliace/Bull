#ifndef BULL_NETWORK_ADDRESS_IPADDRESS_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESS_HPP

#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Network/Address/NetProtocol.hpp>
#include <Bull/Network/Export.hpp>

namespace Bull
{
    struct BULL_NETWORK_API IpAddress
    {
    public:

        static IpAddress Any;
        static IpAddress None;
        static IpAddress Loopback;
        static IpAddress Broadcast;

    public:

        /*! \brief Default constructor
         *
         */
        IpAddress();

        /*! \brief Constructor
         *
         * \param a The first byte of the IpAddressV4
         * \param b The second byte of the IpAddressV4
         * \param c The third byte of the IpAddressV4
         * \param d The forth byte of the IpAddressV4
         *
         */
        IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d);

        /*! \brief Tell whether the IpAddress is valid and can be used
         *
         * \return True if the IpAddress is valid
         *
         */
        bool isValid() const;

        /*! \brief Convert the IpAddressV4 to a String
         *
         * \return The IpAddressV4 as a String
         *
         */
        String toString() const;

        /*! \brief The protocol used by the IpAddressV4
         *
         * \return The NetProtocol
         *
         */
        NetProtocol getProtocol() const;

        /*! \brief Set bytes of the IpAddress
         *
         * \param bytes  Bytes of the IpAddress
         * \param offset Offset of bytes in the IpAddress
         *
         */
        void setBytes(const ByteArray& bytes, std::size_t offset = 0);

        /*! \brief Get bytes of the IpAddressV4
         *
         * \return Bytes of the IpAddressV4
         *
         */
        const ByteArray& getBytes() const;

    private:

        ByteArray m_bytes;
        bool      m_valid;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESS_HPP
