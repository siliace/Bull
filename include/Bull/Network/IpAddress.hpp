#ifndef BULL_IPADDRESS_HPP
#define BULL_IPADDRESS_HPP

#include <array>

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API IpAddress
    {
    public:

        typedef std::array<Uint8, 4> V4;
        typedef std::array<Uint16, 16> V6;

        enum Family
        {
            Ipv4,
            Ipv6
        };

    private:

        /*! \brief Convert an ip v4 to a String
         *
         * \param address The addess to convert to a String
         *
         * \return Return the representation as a String of the address
         *
         */
        static String toString(const V4& address);

        /*! \brief Convert an ip v6 to a String
         *
         * \param address The addess to convert to a String
         *
         * \return Return the representation as a String of the address
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

        /*! \brief Convert an IpAddress to a String
         *
         * \return Return the representation of the IpAddress as a String
         *
         */
        String toString() const;

        /*! \brief Check whether the IpAddress is valid and can be used
         *
         * \return Return true if the IpAddress is valid, false otherwise
         *
         */
        bool isValid() const;

    private:

        union
        {
            V4 m_ipv4;
            V6 m_ipv6;
        };

        bool   m_valid;
        Family m_family;
    };
}

#endif // BULL_IPADDRESS_HPP
