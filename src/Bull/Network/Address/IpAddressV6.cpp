#include <Bull/Network/Address/IpAddressV6.hpp>

namespace Bull
{
    IpAddressV6::IpAddressV6() :
        m_valid(false)
    {
        /// Nothing
    }

    bool IpAddressV6::isValid() const
    {
        return m_valid;
    }

    String IpAddressV6::toString() const
    {
        return "";
    }

    NetProtocol IpAddressV6::getProtocol() const
    {
        return NetProtocol_Ipv6;
    }

    std::size_t IpAddressV6::getByteCount() const
    {
        return 16;
    }

    Uint8& IpAddressV6::at(std::size_t index)
    {
        RangeCheck(index, 16);

        return m_bytes[index];
    }

    Uint8 IpAddressV6::at(std::size_t index) const
    {
        RangeCheck(index, 16);

        return m_bytes[index];
    }
}