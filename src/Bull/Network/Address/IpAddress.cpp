#include <Bull/Network/Address/IpAddress.hpp>
#include <Bull/Network/Address/IpAddressImpl.hpp>

namespace Bull
{
    void IpAddress::resolve(const String& hostname)
    {
        prv::IpAddressImpl::resolve(hostname, getProtocol(), m_bytes);

        m_valid = true;
    }

    bool IpAddress::isValid() const
    {
        return m_valid;
    }

    std::size_t IpAddress::getByteCount() const
    {
        return m_bytes.capacity();
    }

    Uint8& IpAddress::at(std::size_t index)
    {
        m_valid = true;

        return m_bytes[index];
    }

    Uint8 IpAddress::at(std::size_t index) const
    {
        return m_bytes[index];
    }

    IpAddress::IpAddress(std::size_t size, bool valid) :
        m_valid(valid)
    {
        m_bytes.reserve(size);
    }
}
