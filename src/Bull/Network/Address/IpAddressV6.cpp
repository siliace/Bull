#include <Bull/Core/IO/StringStream.hpp>

#include <Bull/Network/Address/IpAddressImpl.hpp>
#include <Bull/Network/Address/IpAddressV6.hpp>

namespace Bull
{
    IpAddressV6::IpAddressV6() :
        m_bytes(16),
        m_valid(false)
    {
        /// Nothing
    }

    void IpAddressV6::resolve(const String& hostname)
    {
        m_valid = prv::IpAddressImpl::resolve(hostname, NetProtocol_Ipv6, m_bytes);
    }

    bool IpAddressV6::isValid() const
    {
        return m_valid;
    }

    String IpAddressV6::toString() const
    {
        StringStream ss;

        for(std::size_t i = 0; i < getByteCount(); i++)
        {
            ss << m_bytes[i];

            if(i < getByteCount() - 1)
            {
                ss << ':';
            }
        }

        return ss.toString();
    }

    NetProtocol IpAddressV6::getProtocol() const
    {
        return NetProtocol_Ipv6;
    }

    std::size_t IpAddressV6::getByteCount() const
    {
        return m_bytes.getCapacity();
    }

    Uint8& IpAddressV6::at(std::size_t index)
    {
        return m_bytes[index];
    }

    Uint8 IpAddressV6::at(std::size_t index) const
    {
        return m_bytes[index];
    }
}