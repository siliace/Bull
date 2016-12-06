#ifndef BULL_IPADDRESS_HPP
#define BULL_IPADDRESS_HPP

#include <array>

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>

namespace Bull
{
    class BULL_API IpAddress
    {
    public:

        enum NetProtocol
        {
            Any,
            IPv4,
            IPv6,
            Unknown
        };

        typedef std::array<Uint8, 4> Ipv4;
        typedef std::array<Uint16, 8> Ipv6;

        static IpAddress None;
        static IpAddress AnyIpv4;
        static IpAddress AnyIpv6;
        static IpAddress LoopbackIpv4;
        static IpAddress LoopbackIpv6;
        static IpAddress BroadcastIpv4;

        /*! \brief Convert an Ipv4 to a String
         *
         * \return Return the representation of the Ipv4 as String
         *
         */
        static String toString(const Ipv4& ipv4);

        /*! \brief Convert an Ipv6 to a String
         *
         * \return Return the representation of the Ipv6 as String
         *
         */
        static String toString(const Ipv6& ipv6);

    public:

        /*! \brief Default constructor
         *
         */
        IpAddress();

        /*! \brief Constructor
         *
         * \param ipv4 The ip v4 The ip address to create
         *
         */
        IpAddress(const Ipv4& ipv4);

        /*! \brief Constructor
         *
         * \param ipv6 The ip v6 The ip address to create
         *
         */
        IpAddress(const Ipv6& ipv6);

        /*! \brief Constructor
         *
         * \param a The first  byte of the address
         * \param b The second byte of the address
         * \param c The third  byte of the address
         * \param d The forth  byte of the address
         *
         */
        IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d);

        /*! \brief Constructor
         *
         * \param a The first   part of the address
         * \param b The second  part of the address
         * \param c The third   part of the address
         * \param d The forth   part of the address
         * \param e The fifth   part of the address
         * \param f The sixth   part of the address
         * \param g The seventh part of the address
         * \param h The eighth  part of the address
         *
         */
        IpAddress(Uint16 a, Uint16 b, Uint16 c, Uint16 d, Uint16 e, Uint16 f, Uint16 g, Uint16 h);

        /*! \brief Check whether if the IpAddress can be used
         *
         * \return Return true if the IpAddress is valid, false otherwise
         *
         */
        bool isValid() const;

        /*! \brief Convert the IpAddress to a String
         *
         * \return Return the representation of the IpAddress as String
         *
         */
        String toString() const;

        /*! \brief Get the NetProtocol used by the IpAddres
         *
         * \return Return the NetProtocol
         *
         */
        NetProtocol getProtocol() const;

    private:

        union
        {
            Ipv4 m_ipv4;
            Ipv6 m_ipv6;
        };

        bool        m_isValid;
        NetProtocol m_protocol;
    };
}

#endif // BULL_IPADDRESS_HPP
