#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/IpAddressImpl.hpp>

namespace Bull
{
    IpAddress IpAddress::None;
    IpAddress IpAddress::AnyIpv4       = IpAddress(0, 0, 0, 0);
    IpAddress IpAddress::AnyIpv6       = IpAddress(0, 0, 0, 0, 0, 0, 0, 0);
    IpAddress IpAddress::LoopbackIpv4  = IpAddress(127, 0, 0, 1);
    IpAddress IpAddress::LoopbackIpv6  = IpAddress(0, 0, 0, 0, 0, 0, 0, 1);
    IpAddress IpAddress::BroadcastIpv4 = IpAddress(255, 255, 255, 255);

    /*! \brief Convert an Ipv4 to a String
     *
     * \return Return the representation of the Ipv4 as String
     *
     */
    String IpAddress::toString(const Ipv4& ipv4)
    {
        StringStream ss;

        ss << ipv4[0] << "." << ipv4[1] << "." << ipv4[2] << "." << ipv4[3];

        return ss;
    }

    /*! \brief Convert an Ipv6 to a String
     *
     * \return Return the representation of the Ipv6 as String
     *
     */
    String IpAddress::toString(const Ipv6& ipv6)
    {
        return String();
    }

    /*! \brief Resolve an host-name to an IpAddress
     *
     * \param hostname The host-name to resolve
     * \param protocol The protocol use by the host to resolve
     *
     * \return Return the IpAddress of the host if the host-name was resolved, IpAddress::None otherwise
     *
     */
    IpAddress IpAddress::resolve(const String& hostname, NetProtocol protocol)
    {

        switch(protocol)
        {
            case NetProtocol::Any:
            case NetProtocol::IPv4:
            case NetProtocol::Unknown:
            {
                if(hostname == AnyIpv4.toString())       return AnyIpv4;
                if(hostname == LoopbackIpv4.toString())  return LoopbackIpv4;
                if(hostname == BroadcastIpv4.toString()) return BroadcastIpv4;

                return prv::IpAddressImpl::resolveIpv4(hostname);
            }

            case NetProtocol::IPv6:
            {
                if(hostname == AnyIpv6.toString())       return AnyIpv6;
                if(hostname == LoopbackIpv6.toString())  return LoopbackIpv6;

                return prv::IpAddressImpl::resolveIpv6(hostname);
            }
        }

        return IpAddress::None;
    }

    /*! \brief Default constructor
     *
     */
    IpAddress::IpAddress() :
        m_isValid(false),
        m_protocol(NetProtocol::Unknown)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param address The representation of the ip as an integer
     *
     */
    IpAddress::IpAddress(Uint32 address) :
        m_isValid(true),
        m_protocol(NetProtocol::IPv4)
    {
        m_ipv4[0] = (address & 0x000000ff);
        m_ipv4[1] = (address & 0x0000ff00) >> 8;
        m_ipv4[2] = (address & 0x00ff0000) >> 16;
        m_ipv4[3] = (address & 0xff000000) >> 24;
    }

    /*! \brief Constructor
     *
     * \param ipv4 The ip v4 The ip address to create
     *
     */
    IpAddress::IpAddress(const Ipv4& ipv4) :
        m_ipv4(ipv4),
        m_isValid(true),
        m_protocol(NetProtocol::IPv4)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param ipv6 The ip v6 The ip address to create
     *
     */
    IpAddress::IpAddress(const Ipv6& ipv6) :
        m_ipv6(ipv6),
        m_isValid(true),
        m_protocol(NetProtocol::IPv6)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param a The first  byte of the address
     * \param b The second byte of the address
     * \param c The third  byte of the address
     * \param d The forth  byte of the address
     *
     */
    IpAddress::IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d) :
        IpAddress(Ipv4({a, b, c, d}))
    {
        /// Nothing
    }

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
    IpAddress::IpAddress(Uint16 a, Uint16 b, Uint16 c, Uint16 d, Uint16 e, Uint16 f, Uint16 g, Uint16 h) :
        IpAddress(Ipv6({a, b, c, d, e, f, g, h}))
    {
        /// Nothing
    }

    /*! \brief Compare two IpAddress
     *
     * \param right The IpAddress to compare to this
     *
     * \return Return true if right and this are equal, false otherwise
     *
     */
    bool IpAddress::operator==(const IpAddress& right)
    {
        return toString() == right.toString();
    }

    /*! \brief Compare two IpAddress
     *
     * \param right The IpAddress to compare to this
     *
     * \return Return true if right and this are not equal, false otherwise
     *
     */
    bool IpAddress::operator!=(const IpAddress& right)
    {
        return toString() != right.toString();
    }

    /*! \brief Check whether if the IpAddress can be used
     *
     * \return Return true if the IpAddress is valid, false otherwise
     *
     */
    bool IpAddress::isValid() const
    {
        return m_isValid;
    }

    /*! \brief Convert the IpAddress to a String
     *
     * \return Return the representation of the IpAddress as String
     *
     */
    String IpAddress::toString() const
    {
        switch(m_protocol)
        {
            case NetProtocol::IPv4: return toString(m_ipv4);
            case NetProtocol::IPv6: return toString(m_ipv6);
            default:                return String();
        }
    }

    /*! \brief Get the NetProtocol used by the IpAddres
     *
     * \return Return the NetProtocol
     *
     */
    IpAddress::NetProtocol IpAddress::getProtocol() const
    {
        return m_protocol;
    }
}
