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
        if(isConnected())
        {
            disconnect();
        }

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

    bool TcpSocket::isConnected() const
    {
        return m_remoteAddress.isValid() && m_remotePort != AnyPort;
    }

    void TcpSocket::disconnect()
    {
        close();

        m_remotePort    = AnyPort;
        m_remoteAddress = IpAddress::None;
    }

    Socket::State TcpSocket::send(const void* data, std::size_t length, std::size_t* sent)
    {
        return Disconnected;
    }

    Socket::State TcpSocket::receive(void* data, std::size_t length)
    {
        return Disconnected;
    }

    void TcpSocket::reset(SocketHandler handler, const IpAddress& address, Socket::Port port)
    {
        if(isConnected())
        {
            disconnect();
        }

        Socket::reset(handler);

        m_remotePort    = port;
        m_remoteAddress = address;
    }
}