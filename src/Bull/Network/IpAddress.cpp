#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    IpAddress IpAddress::None          = IpAddress();
    IpAddress IpAddress::AnyIpv4       = IpAddress(IpAddress::V4({0, 0, 0, 0}));
    IpAddress IpAddress::AnyIpv6       = IpAddress(IpAddress::V6({0, 0, 0, 0, 0, 0, 0, 0}));
    IpAddress IpAddress::LoopbackIpv4  = IpAddress(IpAddress::V4({127, 0, 0, 1}));
    IpAddress IpAddress::LoopbackIpv6  = IpAddress(IpAddress::V6({0, 0, 0, 0, 0, 0, 0, 1}));
    IpAddress IpAddress::BroadcastIpv4 = IpAddress(IpAddress::V4({255, 255, 255, 255}));

    String IpAddress::toString(const V4& address)
    {
        StringStream ss;

        ss << address[0] << '.' << address[1] << '.' << address[2] << '.' << address[3];

        return ss;
    }

    String IpAddress::toString(const V6& address)
    {
        return String();
    }

    IpAddress::IpAddress() :
        m_valid(false)
    {
        /// Nothing
    }

    IpAddress::IpAddress(const V4& ipv4)
    {
        set(ipv4);
    }

    IpAddress::IpAddress(const V6& ipv6)
    {
        set(ipv6);
    }

    void IpAddress::set(const V4& ipv4)
    {
        m_ipv4     = ipv4;
        m_valid    = true;
        m_protocol = NetProtocol::Ipv4;
    }

    void IpAddress::set(const V6& ipv6)
    {
        m_ipv6     = ipv6;
        m_valid    = true;
        m_protocol = NetProtocol::Ipv6;
    }

    String IpAddress::toString() const
    {
        switch(m_protocol)
        {
            case NetProtocol::Ipv4: return toString(m_ipv4);
            case NetProtocol::Ipv6: return toString(m_ipv6);
        }

        return String();
    }

    IpAddress::V4 IpAddress::toV4() const
    {
        if(m_protocol == Ipv4)
        {
            return m_ipv4;
        }

        return IpAddress::V4({0});
    }

    IpAddress::V6 IpAddress::toV6() const
    {
        if(m_protocol == Ipv6)
        {
            return m_ipv6;
        }

        return IpAddress::V6({0});
    }

    bool IpAddress::operator==(const IpAddress& left)
    {
        return toString() == left.toString();
    }

    bool IpAddress::operator!=(const IpAddress& left)
    {
        return toString() != left.toString();
    }

    Uint32 IpAddress::toInteger() const
    {
        if(m_protocol == NetProtocol::Ipv4)
        {
            return Uint32(m_ipv4[0]) << 24 | Uint32(m_ipv4[1]) << 16 | Uint32(m_ipv4[2]) << 8 | Uint32(m_ipv4[3]) << 0;
        }

        return 0;
    }

    bool IpAddress::isValid() const
    {
        return m_valid;
    }

    NetProtocol IpAddress::getProtocol() const
    {
        return m_protocol;
    }
}
