#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>
#include <Bull/Network/Win32/SocketImpl.hpp>

namespace Bull
{
    TcpSocket::TcpSocket() :
        Socket(Tcp),
        m_remotePort(AnyPort),
        m_remoteAddress(IpAddress::None)
    {
        /// Nothing
    }

    Socket::State TcpSocket::connect(const IpAddress& address, Port port)
    {
        if(getHandler() != prv::SocketImpl::InvalidHandler)
        {
            disconnect();
        }

        create(address.getProtocol());

        if(prv::SocketImpl::connect(getHandler(), address, port))
        {
            m_remotePort    = port;
            m_remoteAddress = address;

            return Ready;
        }

        return Disconnected;
    }

    Socket::State TcpSocket::connect(const IpAddress& address, Port port, const Time& timeout)
    {
        Clock timer;
        State state;

        timer.start();

        do
        {
            Thread::sleep(Time::milliseconds(10.f));
            state = connect(address, port);
        }while(timer.getElapsedTime() < timeout && state != Ready);

        return state;
    }

    void TcpSocket::disconnect()
    {
        close();

        m_remotePort    = AnyPort;
        m_remoteAddress = IpAddress::None;
    }

    bool TcpSocket::isConnected() const
    {
        return getHandler() != prv::SocketImpl::InvalidHandler;
    }

    Socket::State TcpSocket::send(const void* data, std::size_t length, std::size_t& sent)
    {
        if(data && length)
        {
            State state;
            std::size_t result = 0;
            for(sent = 0; sent < length; sent += result)
            {
                result = prv::SocketImpl::send(getHandler(), data, length);

                if(result <= 0)
                {
                    state = prv::SocketImpl::lastError();

                    if(state == NotReady && sent > 0)
                    {
                        return Partial;
                    }

                    return state;
                }
            }

            return Ready;
        }
        else
        {
            updateState(Error);
        }

        return m_state;
    }

    Socket::State TcpSocket::receive(void* data, std::size_t length, std::size_t& received)
    {
        received = 0;

        if(!data || length)
        {
            std::size_t result = prv::SocketImpl::receive(getHandler(), data, length);

            if(result > 0)
            {
                received = result;

                updateState(Ready);
            }
            else if(result == 0)
            {
                updateState(Disconnected);
            }
            else
            {
                updateState(prv::SocketImpl::lastError());
            }
        }

        return m_state;
    }

    void TcpSocket::reset(SocketHandler handler, const IpAddress& address, Socket::Port port)
    {
        if(getHandler() != prv::SocketImpl::InvalidHandler)
        {
            disconnect();
        }

        Socket::reset(handler);

        m_remotePort    = port;
        m_state         = Ready;
        m_remoteAddress = address;
    }

    TcpSocket& TcpSocket::updateState(Socket::State state)
    {
        m_state = state;

        return (*this);
    }
}