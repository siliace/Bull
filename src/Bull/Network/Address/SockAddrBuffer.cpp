#include <Bull/Core/Exception/InvalidParameter.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Address/IpAddressV4.hpp>
#include <Bull/Network/Address/IpAddressV6.hpp>

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
            BULL_ZERO_MEMORY(m_addr);

            switch(address.getProtocol())
            {
                case NetProtocol_Ipv4:
                    createFromIpAddressV4(address, port);
                    break;
                case NetProtocol_Ipv6:
                    createFromIpAddressV6(address, port);
                    break;
            }
        }

        NetPort SockAddrBuffer::getPort() const
        {
            switch(m_addr.sa_family)
            {
                case AF_INET:
                    return NetPort(ntohs(reinterpret_cast<const sockaddr_in*>(&m_addr)->sin_port));
                case AF_INET6:
                    return NetPort(ntohs(reinterpret_cast<const sockaddr_in6*>(&m_addr)->sin6_port));
                default:
                    Throw(InvalidParameter, "Unsupported AF type");
            }

            return NetPort_Any;
        }

        std::unique_ptr<IpAddress> SockAddrBuffer::getIpAddress()
        {
            switch(m_addr.sa_family)
            {
                case AF_INET:
                    return createFromSockAddrV4();
                case AF_INET6:
                    return createFromSockAddrV6();
                default:
                    Throw(InvalidParameter, "Unsupported AF type");
            }

            return nullptr;
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
            Uint8* bytes = reinterpret_cast<Uint8*>(&addr->sin_addr);

            m_length = sizeof(sockaddr_in);

            addr->sin_family = AF_INET;
            addr->sin_port = htons(port);
            bytes[0] = address.at(0);
            bytes[1] = address.at(1);
            bytes[2] = address.at(2);
            bytes[3] = address.at(3);
        }

        void SockAddrBuffer::createFromIpAddressV6(const IpAddress& address, NetPort port)
        {
            sockaddr_in6* addr = reinterpret_cast<sockaddr_in6*>(&m_addr);
            Uint8* bytes = reinterpret_cast<Uint8*>(&addr->sin6_addr);

            m_length = sizeof(sockaddr_in6);

            addr->sin6_family = AF_INET6;
            addr->sin6_port = htons(port);

            for(std::size_t i = 0; i < address.getByteCount(); i++)
            {
                bytes[i] = address.at(i);
            }
        }

        std::unique_ptr<IpAddress> SockAddrBuffer::createFromSockAddrV4() const
        {
            const sockaddr_in* addr = reinterpret_cast<const sockaddr_in*>(&m_addr);
            const Uint8* bytes = reinterpret_cast<const Uint8*>(&addr->sin_addr);

            return std::make_unique<IpAddressV4>(bytes[0], bytes[1], bytes[2], bytes[3]);
        }

        std::unique_ptr<IpAddress> SockAddrBuffer::createFromSockAddrV6() const
        {
            const sockaddr_in6* addr = reinterpret_cast<const sockaddr_in6*>(&m_addr);
            const Uint8* bytes = reinterpret_cast<const Uint8*>(&addr->sin6_addr);

            return std::make_unique<IpAddressV6>(ByteArray::memoryCopy(bytes, 16 * sizeof(Uint8)));
        }
    }
}