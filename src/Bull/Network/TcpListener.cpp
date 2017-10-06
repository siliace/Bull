#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Network/SocketImpl.hpp>
#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

#include <Bull/Core/Utility/CallOnExit.hpp>

namespace Bull
{
    TcpListener::TcpListener() :
        Socket(Tcp),
        m_listeningPort(AnyPort)
    {
        /// Nothing
    }

    Socket::State TcpListener::listen(Socket::Port port, unsigned int backlog)
    {
        return listen(port, IpAddress::AnyIpv4, backlog);
    }

    Socket::State TcpListener::listen(Port port, const IpAddress& host, unsigned int backlog)
    {
        if(host.isValid())
        {
            create(host.getProtocol());

            if(!prv::SocketImpl::bind(getHandler(), host, port))
            {
                return Socket::Error;
            }

            if(!prv::SocketImpl::listen(getHandler(), backlog))
            {
                return Socket::Error;
            }

            m_listeningPort = port;

            return Socket::Ready;
        }

        return Socket::Error;
    }

    Socket::State TcpListener::accept(TcpSocket& client)
    {
        if(getHandler() != prv::SocketImpl::InvalidHandler)
        {
            IpAddress ip;
            Socket::Port port;

            SocketHandler clientHandler = prv::SocketImpl::accept(getHandler(), ip, port);

            if(clientHandler == prv::SocketImpl::InvalidHandler)
            {
                return Socket::Disconnected;
            }

            client.reset(clientHandler, ip, port);

            return Socket::Ready;
        }

        return Socket::Disconnected;
    }

    Socket::State TcpListener::accept(TcpSocket& client, const Time& timeout)
    {
        Clock timer;
        Socket::State state;
        bool blockingMode = isEnableBlocking();

        // We need to use the non blocking mode of the Socket
        enableBlocking(false);
        CallOnExit resetBlockingMode([this, blockingMode](){
            enableBlocking(blockingMode);
        });

        timer.start();

        do
        {
            Thread::sleep(Time::milliseconds(10.f));
            state = accept(client);
        }while(timer.getElapsedTime() < timeout && state == Disconnected);

        return state;
    }

    Socket::Port TcpListener::getListeningPort() const
    {
        return m_listeningPort;
    }
}