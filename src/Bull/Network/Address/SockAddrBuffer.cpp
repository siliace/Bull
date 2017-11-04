#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <inaddr.h>

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

        SockAddrBuffer::SockAddrBuffer(const IpAddress& address, NetPort port)
        {
            switch(address.getProtocol())
            {
                case NetProtocol_Ipv4: createFromIpAddressV4(address.getBytes(), port); break;
                case NetProtocol_Ipv6: createFromIpAddressV6(address.getBytes(), port); break;
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

        IpAddress SockAddrBuffer::getIpAddress()
        {
            switch(m_addr.sa_family)
            {
                case AF_INET: return createFromSockAddrV4();
                case AF_INET6: return createFromSockAddrV6();
            }

            return IpAddress::None;
        }

        const sockaddr* SockAddrBuffer::getSockAddr() const
        {
            return &m_addr;
        }

        int SockAddrBuffer::getLength() const
        {
            return m_length;
        }

        void SockAddrBuffer::createFromIpAddressV4(const ByteArray& address, NetPort port)
        {
            sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(&m_addr);

            m_length = sizeof(sockaddr_in);

            addr->sin_family                = AF_INET;
            addr->sin_port                  = htons(port);
            addr->sin_addr.S_un.S_un_b.s_b1 = address[0];
            addr->sin_addr.S_un.S_un_b.s_b2 = address[1];
            addr->sin_addr.S_un.S_un_b.s_b3 = address[2];
            addr->sin_addr.S_un.S_un_b.s_b4 = address[3];
        }

        void SockAddrBuffer::createFromIpAddressV6(const ByteArray& address, NetPort port)
        {
            sockaddr_in6* addr = reinterpret_cast<sockaddr_in6*>(&m_addr);

            m_length = sizeof(sockaddr_in6);

            addr->sin6_family = AF_INET6;
            addr->sin6_port   = htons(port);

            for(std::size_t i = 0; i < address.getCapacity(); i++)
            {
                addr->sin6_addr.u.Byte[i] = address[i];
            }
        }

        IpAddress SockAddrBuffer::createFromSockAddrV4() const
        {
            IpAddress address;
            ByteArray bytes(4);

            const sockaddr_in* addr = reinterpret_cast<const sockaddr_in*>(&m_addr);

            bytes[0] = addr->sin_addr.S_un.S_un_b.s_b1;
            bytes[1] = addr->sin_addr.S_un.S_un_b.s_b2;
            bytes[2] = addr->sin_addr.S_un.S_un_b.s_b3;
            bytes[3] = addr->sin_addr.S_un.S_un_b.s_b4;

            address.setBytes(bytes);

            return address;
        }

        IpAddress SockAddrBuffer::createFromSockAddrV6() const
        {
            IpAddress address;
            ByteArray bytes(16);

            const sockaddr_in6* addr = reinterpret_cast<const sockaddr_in6*>(&m_addr);

            for(std::size_t i = 0; i < bytes.getCapacity(); i++)
            {
                bytes[i] = addr->sin6_addr.u.Byte[i];
            }

            address.setBytes(bytes);

            return address;
        }
    }
}