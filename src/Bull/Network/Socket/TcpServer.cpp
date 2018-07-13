#include <thread>

#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Utility/Finaly.hpp>

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

    TcpServer::~TcpServer()
    {
        disconnect();
    }

    SocketState TcpServer::listen(NetPort port, const IpAddressWrapper& host, int backlog)
    {
        if(port != NetPort_Any && host.isValid() && create(host.getProtocol()))
        {
            m_impl = std::make_unique<prv::TcpServerImpl>(getImpl());

            if(m_impl->bind(host, port))
            {
                if(m_impl->listen(backlog))
                {
                    m_port    = port;
                    m_backlog = backlog;

                    return SocketState();
                }
            }
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    bool TcpServer::isListening() const
    {
        return m_impl != nullptr;
    }

    SocketState TcpServer::accept(TcpClient& client)
    {
        if(isListening())
        {
            NetPort port;
            IpAddressWrapper address;

            SocketHandler socket = m_impl->accept(address, port);

            if(socket != prv::SocketImpl::getInvalidSocket() && client.create(socket, address, port))
            {
                return SocketState();
            }
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    SocketState TcpServer::accept(TcpClient& client, const Duration& timeout, const Duration& pause)
    {
        if(isListening())
        {
            Clock clock;
            bool blocking = isEnableBlockingMode();

            Finaly cleanup([this, blocking](){
                enableBlockingMode(blocking);
            });

            enableBlockingMode(false);

            clock.start();

            do
            {
                if(accept(client))
                {
                    return SocketState();
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<unsigned int>(pause.asMilliseconds())));
            }while(clock.getElapsedTime() < timeout);
        }

        return SocketState(prv::SocketImpl::getLastError());
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