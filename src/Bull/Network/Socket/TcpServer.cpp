#include <thread>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/SocketLength.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>
#include <Bull/Network/Socket/TcpServer.hpp>

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
        std::swap(m_port, right.m_port);
        std::swap(m_backlog, right.m_backlog);
    }

    TcpServer::~TcpServer()
    {
        disconnect();
    }

    TcpServer& TcpServer::operator=(TcpServer&& right) noexcept
    {
        std::swap(m_port, right.m_port);
        std::swap(m_backlog, right.m_backlog);

        Socket::operator=(std::move(right));

        return *this;
    }

    void TcpServer::listen(NetPort port, const IpAddress& host, int backlog)
    {
        Expect(host.isValid(), Throw(InvalidParameter, "TcpServer::listen", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpServer::listen", "Invalid NetPort"));

        int ret;

        create(host.getProtocol());

        prv::SockAddrBuffer buffer(host, port);

        ret = ::bind(getHandler(), buffer.getSockAddr(), buffer.getLength());

        Expect(ret == 0, Throw(InternalError, "TcpServerImpl::bind", "Failed to bind the socket"));

        ret = ::listen(getHandler(), backlog);

        Expect(ret == 0, Throw(InternalError, "TcpServerImpl::listen", "Failed to listen the port"));

        m_port    = port;
        m_backlog = backlog;
    }

    bool TcpServer::isListening() const
    {
        return isValid();
    }

    TcpClient TcpServer::accept()
    {
        Expect(isListening(), Throw(LogicError, "TcpServer::accept", "The TcpServer is not listening"));

        sockaddr addr;
        TcpClient client;
        prv::SocketLength length = sizeof(sockaddr);

        SocketHandler clientHandler = ::accept(getHandler(), &addr, &length);

        Expect(clientHandler != prv::SocketImpl::getInvalidSocket(), Throw(InternalError, "TcpServerImpl::accept", "Failed to accept client"));

        prv::SockAddrBuffer buffer(addr, length);

        client.create(clientHandler, buffer.getIpAddress(), buffer.getPort());

        return client;
    }

    void TcpServer::disconnect()
    {
        close();
        m_backlog = 0;
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