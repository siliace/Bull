#include <Bull/Network/Address/IpAddress.hpp>
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

    bool TcpClient::connect(const IpAddress& address, NetPort port)
    {
        if(create(address.getProtocol()))
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
    }

    bool TcpClient::send(const ByteArray& bytes)
    {

    }

    bool TcpClient::receive(ByteArray& bytes)
    {

    }

    NetPort TcpClient::getRemotePort() const
    {
        return m_hostPort;
    }

    const IpAddress& TcpClient::getRemoteAddress() const
    {
        return m_hostAddress;
    }

    void TcpClient::reset(SocketHandler handler, const IpAddress& address, NetPort port)
    {
        m_hostPort = port;
        m_hostAddress = address;
    }
}