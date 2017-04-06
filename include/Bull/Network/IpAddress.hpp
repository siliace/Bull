#ifndef BULL_IPADDRESS_HPP
#define BULL_IPADDRESS_HPP

#include <array>

#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Network/NetProtocol.hpp>

namespace Bull
{
    class BULL_API IpAddress
    {
    public:

        typedef std::array<Uint8, 4> V4;
        typedef std::array<Uint16, 16> V6;

        static IpAddress None;
        static IpAddress AnyIpv4;
        static IpAddress AnyIpv6;
        static IpAddress LoopbackIpv4;
        static IpAddress LoopbackIpv6;
        static IpAddress BroadcastIpv4;

    private:

        /*! \brief Convert an ip v4 to a String
         *
         * \param address The addess to convert to a String
         *
         * \return The representation as a String of the address
         *
         */
        static String toString(const V4& address);

        /*! \brief Convert an ip v6 to a String
         *
         * \param address The addess to convert to a String
         *
         * \return The representation as a String of the address
         *
         */
        static String toString(const V6& address);

    public:

        /*! \brief Default constructor
         *
         */
        IpAddress();

        /*! \brief Constructor
         *
         * \param ipv4 The ip wanted
         *
         */
        IpAddress(const V4& ipv4);

        /*! \brief Constructor
         *
         * \param ipv6 The ip wanted
         *
         */
        IpAddress(const V6& ipv6);

        /*! \brief Set the ip
         *
         * \param ipv4 The ip
         *
         */
        void set(const V4& ipv4);

        /*! \brief Set the ip
         *
         * \param ipv6 The ip
         *
         */
        void set(const V6& ipv6);

        /*! \brief Convert an IpAddress to a String
         *
         * \return The representation of the IpAddress as a String
         *
         */
        String toString() const;

        /*! \brief Convert an IpAddress to an IpAddress:V4
         *
         * \return Thes equivalent IpAddress::V4 of the IpAddress
         *
         */
        V4 toV4() const;

        /*! \brief Convert an IpAddress to an IpAddress:V6
         *
         * \return The equivalent IpAddress::V6 of the IpAddress
         *
         */
        V6 toV6() const;

        /*! \brief Compare two IpAddress
         *
         * \param left The IpAddress to compare to this
         *
         * \return True if this and left are equal
         *
         */
        bool operator==(const IpAddress& left);

        /*! \brief Compare two IpAddress
         *
         * \param left The IpAddress to compare to this
         *
         * \return True if this and left are not equal
         *
         */
        bool operator!=(const IpAddress& left);

        /*! \brief Convert this IpAddress to an integer
         *
         * \return The equivalent Uint32 of the IpAddress
         *
         */
        Uint32 toInteger() const;

        /*! \brief Check whether the IpAddress is valid and can be used
         *
         * \return True if the IpAddress is valid
         *
         */
        bool isValid() const;

        /*! \brief Get the protocol used the IpAddress
         *
         * \return The protocol
         *
         */
        NetProtocol getProtocol() const;

    private:

        union
        {
            V4 m_ipv4;
            V6 m_ipv6;
        };

        bool        m_valid;
        NetProtocol m_protocol;
    };
}

#endif // BULL_IPADDRESS_HPP
