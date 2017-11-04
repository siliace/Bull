#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpClientImpl.hpp>

namespace Bull
{
    TcpClient::TcpClient() :
        Socket(SocketType_Tcp)
    {
        /// Nothing
    }

    TcpClient::~TcpClient()
    {
        disconnect();
    }

    bool TcpClient::connect(const IpAddressWrapper& address, NetPort port)
    {
        if(Socket::create(address.getProtocol()))
        {
            m_impl = std::make_unique<prv::TcpClientImpl>(getImpl());

            return m_impl->connect(address, port);
        }

        return false;
    }

    bool TcpClient::isConnected() const
    {
        return m_impl != nullptr;
    }

    void TcpClient::disconnect()
    {
        close();
        m_impl.reset();
        m_hostPort = NetPort_Any;
        m_hostAddress = IpAddressV4::None;
    }

    bool TcpClient::send(const void* data, std::size_t length, std::size_t& sent)
    {
        if(isConnected())
        {
            return m_impl->send(data, length, sent);
        }

        return false;
    }

    bool TcpClient::receive(void* data, std::size_t length, std::size_t& sent)
    {
        if(isConnected())
        {
            return m_impl->reveive(data, length, sent);
        }

        return false;
    }

    NetPort TcpClient::getRemotePort() const
    {
        if(isConnected())
        {
            return m_hostPort;
        }

        return NetPort_Any;
    }

    const IpAddress& TcpClient::getRemoteAddress() const
    {
        if(isConnected())
        {
            return m_hostAddress.getAddress();
        }

        return IpAddressV4::None;
    }

    bool TcpClient::create(SocketHandler handler, const IpAddressWrapper& address, NetPort port)
    {
        if(Socket::create(handler))
        {
            m_impl = std::make_unique<prv::TcpClientImpl>(getImpl());
            m_hostPort = port;
            m_hostAddress = address;

            return true;
        }

        return false;
    }
}