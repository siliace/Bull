#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/Address/IpAddress.hpp>

namespace Bull
{
    IpAddress IpAddress::Any = IpAddress(0, 0, 0, 0);
    IpAddress IpAddress::None;
    IpAddress IpAddress::Loopback = IpAddress(127, 0, 0, 1);
    IpAddress IpAddress::Broadcast = IpAddress(255, 255, 255, 255);

    IpAddress::IpAddress() :
        m_valid(false)
    {
        /// Nothing
    }

    IpAddress::IpAddress(Uint8 a, Uint8 b, Uint8 c, Uint8 d) :
        m_valid(true)
    {
        if(m_bytes.create(4))
        {
            m_bytes[0] = a;
            m_bytes[1] = b;
            m_bytes[2] = c;
            m_bytes[3] = d;
        }
    }

    bool IpAddress::isValid() const
    {
        return m_valid;
    }

    String IpAddress::toString() const
    {
        StringStream ss;

        for(std::size_t i = 0; i < m_bytes.getCapacity(); i++)
        {
            ss << m_bytes[i];

            if(i < 3)
            {
                ss << '.';
            }
        }

        return ss.toString();
    }

    NetProtocol IpAddress::getProtocol() const
    {
        return NetProtocol_Ipv4;
    }

    void IpAddress::setBytes(const ByteArray& bytes, size_t offset)
    {
        if(bytes.getCapacity() + offset <= 4)
        {
            if(!m_bytes.fill(bytes.getBuffer(), bytes.getCapacity(), offset))
            {
                throw RuntimeError("Failed to copy bytes");
            }
        }

        throw LogicError("Invalid length of bytes or offset", "bytes capacity + offset should be lower or equal to 4");
    }

    const ByteArray& IpAddress::getBytes() const
    {
        return m_bytes;
    }
}