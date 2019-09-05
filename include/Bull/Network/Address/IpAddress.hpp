#ifndef BULL_NETWORK_ADDRESS_IPADDRESS_HPP
#define BULL_NETWORK_ADDRESS_IPADDRESS_HPP

#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Network/Export.hpp>
#include <Bull/Network/Address/NetProtocol.hpp>

namespace Bull
{
    class BULL_NETWORK_API IpAddress
    {
    public:

        /** \brief \brief Resolve an hostname to an IpAddress
         *
         * \param hostname The hostname to resolve
         *
         */
        void resolve(const std::string& hostname);

        /** \brief Tell whether the IpAddress is valid
         *
         * \return True if the IpAddress is valid
         *
         */
        bool isValid() const;

        /** \brief Convert the IpAddress to a std::string
         *
         * \return The IpAddress as a std::string
         *
         */
        virtual std::string toString() const = 0;

        /** \brief Get the NetProtocol used by the IpAddress
         *
         * \return The NetProtocol
         *
         */
        virtual NetProtocol getProtocol() const = 0;

        /** \brief Get the number of bytes used by the IpAddress
         *
         * \return The number of bytes
         *
         */
        std::size_t getByteCount() const;

        /** \brief Get a byte of the IpAddress
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        Uint8& at(std::size_t index);

        /** \brief Get a byte of the IpAddress
         *
         * \param index The index of the byte
         *
         * \return The byte
         *
         */
        Uint8 at(std::size_t index) const;

        /** \brief Compare two IpAddress
         *
         * \param right The IpAddress to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const IpAddress& right) const;

        /** \brief Compare two IpAddress
         *
         * \param right The IpAddress to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const IpAddress& right) const;

    protected:

        /** \brief Constructor
         *
         * \param size  The byte count of the IpAddress
         * \param valid True if the IpAddress is valid
         *
         */
        explicit IpAddress(std::size_t size, bool valid = true);

        ByteArray m_bytes;

    private:

        bool m_valid;
    };
}

#endif // BULL_NETWORK_ADDRESS_IPADDRESS_HPP
