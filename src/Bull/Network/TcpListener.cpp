#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Network/SocketImpl.hpp>
#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

#include <Bull/Core/Utility/CallOnExit.hpp>

namespace Bull
{
    TcpListener::TcpListener() :
        Socket(SocketType_Tcp),
        m_listeningPort(NetPort_Any)
    {
        /// Nothing
    }

    SocketState TcpListener::listen(NetPort port, unsigned int backlog)
    {
        return listen(port, IpAddress::AnyIpv4, backlog);
    }

    SocketState TcpListener::listen(NetPort port, const IpAddress& host, unsigned int backlog)
    {
        if(host.isValid())
        {
            create(host.getProtocol());

            if(!prv::SocketImpl::bind(getHandler(), host, port))
            {
                return SocketState_Error;
            }

            if(!prv::SocketImpl::listen(getHandler(), backlog))
            {
                return SocketState_Error;
            }

            m_listeningPort = port;

            return SocketState_Ready;
        }

        return SocketState_Error;
    }

    SocketState TcpListener::accept(TcpSocket& client)
    {
        if(getHandler() != prv::SocketImpl::InvalidHandler)
        {
            IpAddress ip;
            NetPort port;

            SocketHandler clientHandler = prv::SocketImpl::accept(getHandler(), ip, port);

            if(clientHandler == prv::SocketImpl::InvalidHandler)
            {
                return SocketState_Disconnected;
            }

            client.reset(clientHandler, ip, port);

            return SocketState_Ready;
        }

        return SocketState_Disconnected;
    }

    SocketState TcpListener::accept(TcpSocket& client, const Time& timeout)
    {
        Clock timer;
        SocketState state;
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
        }while(timer.getElapsedTime() < timeout && state == SocketState_Disconnected);

        return state;
    }

    NetPort TcpListener::getListeningPort() const
    {
        return m_listeningPort;
    }
}