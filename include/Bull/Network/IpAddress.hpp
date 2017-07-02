#ifndef BULL_NETWORK_IPADDRESS_HPP
#define BULL_NETWORK_IPADDRESS_HPP

#include <array>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>

#include <Bull/Network/Export.hpp>
#include <Bull/Network/NetProtocol.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddress
    {
    public:

        using V4 = std::array<Uint8, 4>;
        using V6 = std::array<Uint16, 8>;

        static IpAddress None;
        static IpAddress AnyIpv4;
        static IpAddress AnyIpv6;
        static IpAddress LoopbackIpv4;
        static IpAddress LoopbackIpv6;
        static IpAddress BroadcastIpv4;

        /*! \brief Resolve an hostname
         *
         * \param hostname The hostname to resolve
         *
         * \return The IpAddress
         *
         */
        static IpAddress resolve(const String& hostname);

        /*! \brief
         *
         * \param ip
         *
         * \return
         *
         */
        static String toString(const V4& ip);

        /*! \brief
         *
         * \param ip
         *
         * \return
         *
         */
        static String toString(const V6& ip);

    public:

        /*! \brief Default constructor
         *
         */
        IpAddress();

        /*! \brief Constructor
         *
         * \param v4 The IPV4 address
         *
         */
        IpAddress(const V4& v4);

        /*! \brief Constructor
         *
         * \param v6 The IPV6 address
         *
         */
        IpAddress(const V6& v6);

        /*! \brief Constructor
         *
         * \param a
         * \param b
         * \param c
         * \param d
         *
         */
        IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d);

        /*! \brief Compare two IpAddress
         *
         * \param right The IpAddress to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const IpAddress& right) const;

        /*! \brief Compare two IpAddress
         *
         * \param right The IpAddress to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const IpAddress& right) const;

        /*! \brief Get a representation of the IpAddress as a String
         *
         * \return The IpAddress as a String
         *
         */
        String toString() const;

        /*! \brief
         *
         * \return
         *
         */
        Uint32 toUint32() const;

        /*! \brief
         *
         * \return
         *
         */
        bool isValid() const;

        /*! \brief
         *
         * \return
         *
         */
        operator bool() const;

        /*! \brief Get the protocol used by the IpAddress
         *
         * \return The protocol
         *
         */
        NetProtocol getProtocol() const;

    private:

        union
        {
            V4 m_v4;
            V6 m_v6;
        };

        bool        m_valid;
        NetProtocol m_protocol;
    };
}

#endif // BULL_NETWORK_IPADDRESS_HPP
