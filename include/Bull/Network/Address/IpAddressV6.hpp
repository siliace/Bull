#ifndef BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddressV6 : public IpAddress
    {
    public:

        /*! \brief Default constructor
         *
         */
        IpAddressV6();

        /*! \brief Tell whether the IpAddressV6 is valid
         *
         * \return True if the IpAddressV6 is valid
         *
         */
        bool isValid() const override;

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

        /*! \brief Get the number of bytes used by the IpAddressV6
         *
         * \return The number of bytes
         *
         */
        std::size_t getByteCount() const override;

        /*! \brief Get a byte of the IpAddressV6
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        Uint8& at(std::size_t index) override;

        /*! \brief Get a byte of the IpAddressV6
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        Uint8 at(std::size_t index) const override;

    private:

        std::array<Uint8, 16> m_bytes;
        bool                  m_valid;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESSV6_HPP
