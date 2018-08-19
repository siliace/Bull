#include <Bull/Network/Address/IpAddress.hpp>
#include <Bull/Network/Address/IpAddressWrapper.hpp>

namespace Bull
{
    IpAddressWrapper::IpAddressWrapper() :
        IpAddressWrapper(IpAddressV4::None)
    {
        /// Nothing
    }

    IpAddressWrapper::IpAddressWrapper(const IpAddressV4& address) :
        m_protocol(NetProtocol_Ipv4)
    {
        m_wrapper.v4 = address;
    }

    IpAddressWrapper::IpAddressWrapper(const IpAddressV6& address) :
        m_protocol(NetProtocol_Ipv6)
    {
        m_wrapper.v6 = address;
    }

    IpAddressWrapper::IpAddressWrapper(const IpAddressWrapper& copy) :
        m_protocol(copy.getProtocol())
    {
        if(m_protocol == NetProtocol_Ipv4)
        {
            m_wrapper.v4 = copy.m_wrapper.v4;
        }
        else
        {
            m_wrapper.v6 = copy.m_wrapper.v6;
        }
    }

    IpAddressWrapper& IpAddressWrapper::operator=(const IpAddressWrapper& copy)
    {
        if(m_protocol == NetProtocol_Ipv4)
        {
            m_wrapper.v4 = copy.m_wrapper.v4;
        }
        else
        {
            m_wrapper.v6 = copy.m_wrapper.v6;
        }

        return (*this);
    }

    IpAddressWrapper::IpAddressWrapper(IpAddressWrapper&& right) noexcept
    {
        std::swap(m_wrapper, right.m_wrapper);
        std::swap(m_protocol, right.m_protocol);
    }

    IpAddressWrapper& IpAddressWrapper::operator=(IpAddressWrapper&& right) noexcept
    {
        std::swap(m_wrapper, right.m_wrapper);
        std::swap(m_protocol, right.m_protocol);

        return *this;
    }

    bool IpAddressWrapper::isValid() const
    {
        return getAddress().isValid();
    }

    NetProtocol IpAddressWrapper::getProtocol() const
    {
        return m_protocol;
    }

    const IpAddress& IpAddressWrapper::getAddress() const
    {
        if(m_protocol == NetProtocol_Ipv6)
        {
            return m_wrapper.v6;
        }

        return m_wrapper.v4;
    }
}