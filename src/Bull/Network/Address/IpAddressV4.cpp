#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/Address/IpAddressV4.hpp>

namespace Bull
{
    IpAddressV4 IpAddressV4::Any = IpAddressV4(0, 0, 0, 0);
    IpAddressV4 IpAddressV4::None;
    IpAddressV4 IpAddressV4::Loopback = IpAddressV4(127, 0, 0, 1);
    IpAddressV4 IpAddressV4::Broadcast = IpAddressV4(255, 255, 255, 255);

    IpAddressV4::IpAddressV4() :
        m_valid(false)
    {
        /// Nothing
    }

    IpAddressV4::IpAddressV4(Uint32 address) :
        m_valid(true)
    {
        /// Todo
    }

    IpAddressV4::IpAddressV4(Uint8 a, Uint8 b, Uint8 c, Uint8 d) :
        m_valid(true)
    {
        m_bytes[0] = a;
        m_bytes[1] = b;
        m_bytes[2] = c;
        m_bytes[3] = d;
    }

    bool IpAddressV4::isValid() const
    {
        return m_valid;
    }

    String IpAddressV4::toString() const
    {
        StringStream ss;

        for(std::size_t i = 0; i < m_bytes.size(); i++)
        {
            ss << m_bytes[i];

            if(i < 3)
            {
                ss << '.';
            }
        }

        return ss.toString();
    }

    NetProtocol IpAddressV4::getProtocol() const
    {
        return NetProtocol_Ipv4;
    }

    std::size_t IpAddressV4::getByteCount() const
    {
        return 4;
    }

    Uint8& IpAddressV4::at(std::size_t index)
    {
        RangeCheck(index, m_bytes.size());

        return m_bytes.at(index);
    }

    Uint8 IpAddressV4::at(std::size_t index) const
    {
        RangeCheck(index, m_bytes.size());

        return m_bytes.at(index);
    }
}