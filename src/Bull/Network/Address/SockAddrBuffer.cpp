#include <Bull/Core/Configuration/Macro.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>

namespace Bull
{
    namespace prv
    {
        SockAddrBuffer::SockAddrBuffer(const sockaddr& address, int length) :
            m_addr(address),
            m_length(length)
        {
            /// Nothing
        }

        SockAddrBuffer::SockAddrBuffer(const IpAddressWrapper& wrapper, NetPort port)
        {
            BULL_ZERO_MEMORY(m_addr);

            switch(wrapper.getProtocol())
            {
                case NetProtocol_Ipv4: createFromIpAddressV4(wrapper.getAddress(), port); break;
                case NetProtocol_Ipv6: createFromIpAddressV6(wrapper.getAddress(), port); break;
            }
        }

        NetPort SockAddrBuffer::getPort() const
        {
            switch(m_addr.sa_family)
            {
                case AF_INET: return NetPort(ntohs(reinterpret_cast<const sockaddr_in*>(&m_addr)->sin_port));
                case AF_INET6: return NetPort(ntohs(reinterpret_cast<const sockaddr_in6*>(&m_addr)->sin6_port));
            }

            return NetPort_Any;
        }

        IpAddressWrapper SockAddrBuffer::getIpAddress()
        {
            switch(m_addr.sa_family)
            {
                case AF_INET: return createFromSockAddrV4();
                case AF_INET6: return createFromSockAddrV6();
            }

            return IpAddressV4::None;
        }

        const sockaddr* SockAddrBuffer::getSockAddr() const
        {
            return &m_addr;
        }

        int SockAddrBuffer::getLength() const
        {
            return m_length;
        }

        void SockAddrBuffer::createFromIpAddressV4(const IpAddress& address, NetPort port)
        {
            sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(&m_addr);

            m_length = sizeof(sockaddr_in);

            addr->sin_family                = AF_INET;
            addr->sin_port                  = htons(port);
            addr->sin_addr.S_un.S_un_b.s_b1 = address.at(0);
            addr->sin_addr.S_un.S_un_b.s_b2 = address.at(1);
            addr->sin_addr.S_un.S_un_b.s_b3 = address.at(2);
            addr->sin_addr.S_un.S_un_b.s_b4 = address.at(3);
        }

        void SockAddrBuffer::createFromIpAddressV6(const IpAddress& address, NetPort port)
        {
            sockaddr_in6* addr = reinterpret_cast<sockaddr_in6*>(&m_addr);

            m_length = sizeof(sockaddr_in6);

            addr->sin6_family = AF_INET6;
            addr->sin6_port   = htons(port);

            for(std::size_t i = 0; i < address.getByteCount(); i++)
            {
                addr->sin6_addr.u.Byte[i] = address.at(i);
            }
        }

        IpAddressV4 SockAddrBuffer::createFromSockAddrV4() const
        {
            const sockaddr_in* addr = reinterpret_cast<const sockaddr_in*>(&m_addr);

            return IpAddressV4(addr->sin_addr.S_un.S_un_b.s_b1,
                               addr->sin_addr.S_un.S_un_b.s_b2,
                               addr->sin_addr.S_un.S_un_b.s_b3,
                               addr->sin_addr.S_un.S_un_b.s_b4);
        }

        IpAddressV6 SockAddrBuffer::createFromSockAddrV6() const
        {
            IpAddressV6 address;
            const sockaddr_in6* addr = reinterpret_cast<const sockaddr_in6*>(&m_addr);

            for(std::size_t i = 0; i < 16; i++)
            {
                address.at(i) = addr->sin6_addr.u.Byte[i];
            }

            return address;
        }
    }
}