#ifndef BULL_NETWORK_IPADDRESS_HPP
#define BULL_NETWORK_IPADDRESS_HPP

#include <array>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>

#include <Bull/Network/Export.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddress
    {
    public:

        using V4 = std::array<Uint8, 4>;
        using V6 = std::array<Uint16, 8>;

        /*! \brief Resolve an hostname
         *
         * \param hostname The hostname to resolve
         *
         * \return The IpAddress
         *
         */
        IpAddress resolve(const String& hostname);

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

    private:

        union
        {
            V4 m_v4;
            V6 m_v6;
        };

        bool m_valid;
    };
}

#endif // BULL_NETWORK_IPADDRESS_HPP
