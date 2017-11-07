#include <Bull/Network/Address/IpAddress.hpp>
#include <Bull/Network/Address/IpAddressImpl.hpp>

namespace Bull
{
    void IpAddress::resolve(const String& hostname)
    {
        m_valid = prv::IpAddressImpl::resolve(hostname, getProtocol(), m_bytes);
    }

    bool IpAddress::isValid() const
    {
        return m_valid;
    }

    std::size_t IpAddress::getByteCount() const
    {
        return m_bytes.getCapacity();
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
        m_bytes.create(size);
    }
}
