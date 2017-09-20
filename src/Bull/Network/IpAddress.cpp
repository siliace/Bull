#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    IpAddress IpAddress::None;
    IpAddress IpAddress::AnyIpv4(0, 0, 0, 0);
    IpAddress IpAddress::AnyIpv6;
    IpAddress IpAddress::LoopbackIpv4(127, 0, 0, 1);
    IpAddress IpAddress::LoopbackIpv6;
    IpAddress IpAddress::BroadcastIpv4(255, 255, 255, 255);

    IpAddress IpAddress::resolve(const String& hostname)
    {

    }

    String IpAddress::toString(const V4& ip)
    {
        StringStream ss;

        for(unsigned int i = 0; i < ip.size(); i++)
        {
            ss << ip[i];

            if(i < 3)
            {
                ss << ".";
            }
        }

        return ss.toString();
    }

    String IpAddress::toString(const V6& ip)
    {

    }

    IpAddress::IpAddress() :
        m_valid(false),
        m_protocol(IpAddress::Unknown)
    {
        /// Nothing
    }

    IpAddress::IpAddress(const V4& v4) :
        m_v4(v4),
        m_valid(true),
        m_protocol(IpAddress::IpV4)
    {
        /// Nothing
    }

    IpAddress::IpAddress(const V6& v6) :
        m_v6(v6),
        m_valid(true),
        m_protocol(IpAddress::IpV6)
    {
        /// Nothing
    }

    IpAddress::IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d) :
        m_valid(true),
        m_protocol(IpAddress::IpV4)
    {
        m_v4[0] = a;
        m_v4[1] = b;
        m_v4[2] = c;
        m_v4[3] = d;
    }

    bool IpAddress::operator==(const IpAddress& right) const
    {
        return toString() == right.toString();
    }

    bool IpAddress::operator!=(const IpAddress& right) const
    {
        return toString() != right.toString();
    }

    String IpAddress::toString() const
    {
        if(m_protocol == IpAddress::IpV4)
        {
            return toString(m_v4);
        }
        else if(m_protocol == IpAddress::IpV6)
        {
            return toString(m_v6);
        }

        return String();
    }

    Uint32 IpAddress::toUint32() const
    {
        if(!isValid() || m_protocol != IpAddress::IpV4)
        {
            throw LogicError("The Ip is not valid or not Ipv4");
        }

        return Uint32(m_v4[0]) << 24 | Uint32(m_v4[1]) << 16 | Uint32(m_v4[2]) << 8 | Uint32(m_v4[3]) << 0;
    }

    bool IpAddress::isValid() const
    {
        return m_valid;
    }

    IpAddress::operator bool() const
    {
        return isValid();
    }

    IpAddress::NetProtocol IpAddress::getProtocol() const
    {
        return m_protocol;
    }
}