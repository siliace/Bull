#include <Bull/Network/SocketImpl.hpp>
#include <Bull/Network/TcpListener.hpp>
#include <Bull/Network/TcpSocket.hpp>

namespace Bull
{
    TcpListener::TcpListener() :
        Socket(Tcp)
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

            client.create(clientHandler);

            return Socket::Ready;
        }

        return Socket::Disconnected;
    }

    Socket::Port TcpListener::getListeningPort() const
    {
        return Socket::AnyPort;
    }
}