#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Utility/CallOnExit.hpp>

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

    bool TcpServer::listen(NetPort port, const IpAddressWrapper& host, int backlog)
    {
        if(create(host.getProtocol()))
        {
            m_impl = std::make_unique<prv::TcpServerImpl>(getImpl());

            if(m_impl->bind(host, port))
            {
                if(m_impl->listen(backlog))
                {
                    m_port    = port;
                    m_backlog = backlog;

                    return true;
                }
            }
        }

        return false;
    }

    bool TcpServer::isListening() const
    {
        return m_impl != nullptr;
    }

    bool TcpServer::accept(TcpClient& client)
    {
        if(isListening())
        {
            NetPort port;
            IpAddressWrapper address;

            SocketHandler socket = m_impl->accept(address, port);

            if(socket != prv::SocketImpl::getInvalidSocket())
            {
                return client.create(socket, address, port);
            }
        }

        return false;
    }

    bool TcpServer::accept(TcpClient& client, const Time& timeout, const Time& pause)
    {
        if(isListening())
        {
            Clock clock;
            bool connected;
            bool blocking = isEnableBlockingMode();

            CallOnExit cleanup([this, blocking](){
                enableBlockingMode(blocking);
            });

            enableBlockingMode(false);

            clock.start();

            do
            {
                connected = accept(client);

                if(!connected)
                {
                    Thread::sleep(pause);
                }
            }while(!connected && clock.getElapsedTime() < timeout);

            return connected;
        }

        return false;
    }

    void TcpServer::disconnect()
    {
        close();
        m_impl.reset();
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