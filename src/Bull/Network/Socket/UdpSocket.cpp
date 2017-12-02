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

    SocketState UdpSocket::bind(NetPort port, const IpAddressWrapper& address)
    {
        if(create(address.getProtocol()) && address.isValid() && port != NetPort_Any)
        {
            m_impl = std::unique_ptr<prv::UdpSocketImpl>(new prv::UdpSocketImpl(getImpl()));

            if(m_impl->bind(port, address))
            {
                return SocketState();
            }
            else
            {
                unbind();
            }
        }

        return SocketState(prv::SocketImpl::getLastError());
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

    SocketState UdpSocket::sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const
    {
        if(isBound() && address.isValid() && port != NetPort_Any && data && length && m_impl->sendTo(address, port, data, length, sent))
        {
            return SocketState();
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    SocketState UdpSocket::receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const
    {
        if(data && length && m_impl->receiveFrom(address, port, data, length, received))
        {
            return SocketState();
        }

        return SocketState(prv::SocketImpl::getLastError());
    }
}