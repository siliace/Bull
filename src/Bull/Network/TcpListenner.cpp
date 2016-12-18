#include <Bull/Network/SocketImpl.hpp>
#include <Bull/Network/TcpListenner.hpp>
#include <Bull/Network/TcpSocket.hpp>

namespace Bull
{
    TcpListenner::TcpListenner() :
        Socket(Socket::Tcp),
        m_boundPort(0),
        m_boundAddress(IpAddress::None)
    {
        /// Nothing
    }

    Socket::State TcpListenner::listen(NetProtocol protocol, Uint16 port, Socket::Error* error)
    {
        switch(protocol)
        {
            case NetProtocol::Ipv4: return listen(IpAddress::AnyIpv4, port, DefaultQueueLength, error);
            case NetProtocol::Ipv6: return listen(IpAddress::AnyIpv6, port, DefaultQueueLength, error);
        }

        return Socket::State::NotConnected;
    }

    Socket::State TcpListenner::listen(const IpAddress& address, Uint16 port, Socket::Error* error)
    {
        return listen(address, port, DefaultQueueLength, error);
    }

    Socket::State TcpListenner::listen(NetProtocol protocol, Uint16 port, std::size_t queueLength, Socket::Error* error)
    {
        switch(protocol)
        {
            case NetProtocol::Ipv4: return listen(IpAddress::AnyIpv4, port, queueLength, error);
            case NetProtocol::Ipv6: return listen(IpAddress::AnyIpv6, port, queueLength, error);
        }

        return Socket::State::NotConnected;
    }

    Socket::State TcpListenner::listen(const IpAddress& address, Uint16 port, std::size_t queueLength, Socket::Error* error)
    {
        if(address.isValid() && port > 0 && queueLength > 0)
        {
            close();

            if(create(address.getProtocol()))
            {
                Socket::State state = prv::SocketImpl::listen(m_handler, address, port, queueLength, error);

                if(state == Socket::State::Bound)
                {
                    m_boundPort    = port;
                    m_boundAddress = address;
                }

                return state;
            }
        }

        return Socket::State::NotConnected;
    }

    bool TcpListenner::accept(TcpSocket* client, Socket::Error* error)
    {
        if(isListening() && client)
        {
            Uint16        clientPort;
            IpAddress     clientAddress;
            SocketHandler handler = prv::SocketImpl::accept(m_handler, clientAddress, clientPort, error);

            if(handler != prv::SocketImpl::InvalidHandler)
            {
                client->reset(handler, clientAddress, clientPort);

                return true;
            }
        }

        return false;
    }

    bool TcpListenner::isListening()
    {
        return m_handler != prv::SocketImpl::InvalidHandler;
    }
}
