#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    /*! \brief Convert an ip v4 to a String
     *
     * \param address The addess to convert to a String
     *
     * \return Return the representation as a String of the address
     *
     */
    String IpAddress::toString(const V4& address)
    {
        StringStream ss;

        ss << address[0] << '.' << address[1] << '.' << address[2] << '.' << address[3];

        return ss;
    }

    /*! \brief Convert an ip v6 to a String
     *
     * \param address The addess to convert to a String
     *
     * \return Return the representation as a String of the address
     *
     */
    String IpAddress::toString(const V6& address)
    {
        return String();
    }

    /*! \brief Default constructor
     *
     */
    IpAddress::IpAddress() :
        m_valid(false)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param ipv4 The ip wanted
     *
     */
    IpAddress::IpAddress(const V4& ipv4) :
        m_ipv4(ipv4),
        m_valid(false),
        m_family(Family::Ipv4)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param ipv6 The ip wanted
     *
     */
    IpAddress::IpAddress(const V6& ipv6) :
        m_ipv6(ipv6),
        m_valid(false),
        m_family(Family::Ipv6)
    {
        /// Nothing
    }

    /*! \brief Convert an IpAddress to a String
     *
     * \return Return the representation of the IpAddress as a String
     *
     */
    String IpAddress::toString() const
    {
        switch(m_family)
        {
            case Ipv4: return toString(m_ipv4);
            case Ipv6: return toString(m_ipv6);
        }

        return String();
    }

    /*! \brief Check whether the IpAddress is valid and can be used
     *
     * \return Return true if the IpAddress is valid, false otherwise
     *
     */
    bool IpAddress::isValid() const
    {
        return m_valid;
    }
}
