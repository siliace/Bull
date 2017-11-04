#include <Bull/Network/Socket/UdpSocket.hpp>
#include <Bull/Network/Socket/UdpSocketImpl.hpp>

namespace Bull
{
    UdpSocket::UdpSocket() :
        Socket(SocketType_Udp)
    {
        /// Nothing
    }

    UdpSocket::~UdpSocket()
    {
        unbind();
    }

    bool UdpSocket::bind(NetPort port, const IpAddressWrapper& address)
    {
        if(create(address.getProtocol()) && address.isValid() && port != NetPort_Any)
        {
            m_impl = std::make_unique<prv::UdpSocketImpl>(getImpl());

            if(m_impl->bind(port, address))
            {
                return true;
            }
            else
            {
                unbind();
            }
        }

        return false;
    }

    bool UdpSocket::isBound() const
    {
        return m_impl != nullptr;
    }

    void UdpSocket::unbind()
    {
        close();
        m_impl.reset();
    }

    bool UdpSocket::sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const
    {
        if(isBound() && address.isValid() && port != NetPort_Any && data && length)
        {
            return m_impl->sendTo(address, port, data, length, sent) == 0;
        }

        return false;
    }

    bool UdpSocket::receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const
    {
        if(data && length)
        {
            return m_impl->receiveFrom(address, port, data, length, received);
        }

        return false;
    }
}