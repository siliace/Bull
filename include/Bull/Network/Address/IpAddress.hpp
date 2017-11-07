#ifndef BULL_NETWORK_ADDRESS_IPADDRESS_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESS_HPP

#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Network/Export.hpp>
#include <Bull/Network/Address/NetProtocol.hpp>

namespace Bull
{
    struct BULL_NETWORK_API IpAddress
    {
        /*! \brief \brief Resolve an hostname to an IpAddress
         *
         * \param hostname The hostname to resolve
         *
         */
        virtual void resolve(const String& hostname) = 0;

        /*! \brief Tell whether the IpAddress is valid
         *
         * \return True if the IpAddress is valid
         *
         */
        virtual bool isValid() const = 0;

        /*! \brief Convert the IpAddress to a String
         *
         * \return The IpAddress as a String
         *
         */
        virtual String toString() const = 0;

        /*! \brief Get the NetProtocol used by the IpAddress
         *
         * \return The NetProtocol
         *
         */
        virtual NetProtocol getProtocol() const = 0;

        /*! \brief Get the number of bytes used by the IpAddress
         *
         * \return The number of bytes
         *
         */
        virtual std::size_t getByteCount() const = 0;

        /*! \brief Get a byte of the IpAddress
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        virtual Uint8& at(std::size_t index) = 0;

        /*! \brief Get a byte of the IpAddress
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        virtual Uint8 at(std::size_t index) const = 0;

    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESS_HPP
