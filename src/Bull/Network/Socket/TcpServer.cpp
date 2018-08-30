#include <thread>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Network/Socket/SocketImpl.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>
#include <Bull/Network/Socket/TcpServerImpl.hpp>

namespace Bull
{
    TcpServer::TcpServer() :
        Socket(SocketType_Tcp),
        m_port(NetPort_Any),
        m_backlog(0)
    {
        /// Nothing
    }

    TcpServer::TcpServer(TcpServer&& right) noexcept :
        Socket(std::move(right))
    {
        std::swap(m_impl, right.m_impl);
        std::swap(m_port, right.m_port);
        std::swap(m_backlog, right.m_backlog);
    }

    TcpServer::~TcpServer()
    {
        disconnect();
    }

    TcpServer& TcpServer::operator=(TcpServer&& right) noexcept
    {
        std::swap(m_impl, right.m_impl);
        std::swap(m_port, right.m_port);
        std::swap(m_backlog, right.m_backlog);

        Socket::operator=(std::move(right));

        return *this;
    }

    void TcpServer::listen(NetPort port, const IpAddressWrapper& host, int backlog)
    {
        Expect(host.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        create(host.getProtocol());

        m_impl = std::make_unique<prv::TcpServerImpl>(getImpl());

        m_impl->bind(host, port);

        m_impl->listen(backlog);

        m_port    = port;
        m_backlog = backlog;
    }

    bool TcpServer::isListening() const
    {
        return m_impl != nullptr;
    }

    TcpClient TcpServer::accept()
    {
        NetPort port;
        TcpClient client;
        IpAddressWrapper address;

        Expect(isListening(), Throw(LogicError, "TcpServer::accept", "The TcpServer is not listening"));

        client.create(m_impl->accept(address, port), address, port);

        return client;
    }

    void TcpServer::disconnect()
    {
        close();
        m_backlog = 0;
        m_impl.reset();
        m_port = NetPort_Any;
    }

    int TcpServer::getBacklog() const
    {
        return m_backlog;
    }

    NetPort TcpServer::getPort() const
    {
        return m_port;
    }
}