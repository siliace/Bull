#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Network/SocketImpl.hpp>
#include <Bull/Network/TcpSocket.hpp>

#include <Bull/Utility/CallOnExit.hpp>

namespace Bull
{
    TcpSocket::TcpSocket() :
        Socket(Type::Tcp),
        m_peerPort(0),
        m_peerAddress(IpAddress::None)
    {
        /// Nothing
    }

    TcpSocket::~TcpSocket()
    {
        disconnect();
    }

    Socket::State TcpSocket::connect(const IpAddress& address, Uint16 port, const Time& timeout, Socket::Error* error)
    {
        if(address.isValid() && port > 0)
        {
            Clock timer;
            bool  blockingState = isEnableBlockingMode();
            CallOnExit resetBlockingMode([this, blockingState]()
            {
                enableBlockingMode(blockingState);
            });

            disconnect();
            create(address.getProtocol());
            enableBlockingMode(true);

            timer.start();

            do
            {
                m_state = prv::SocketImpl::connect(m_handler, address, port, error);

                if(m_state == Socket::State::NotConnected)
                {
                    Thread::sleep(Time::milliseconds(50.f));
                }
            }while(m_state == Socket::State::NotConnected && timer.getElapsedTime() < timeout);

            if(m_state == Socket::State::Connected)
            {
                m_peerPort    = port;
                m_peerAddress = address;
            }

            return m_state;
        }

        return Socket::State::NotConnected;
    }

    void TcpSocket::disconnect()
    {
        close();
    }

    void TcpSocket::reset(SocketHandler handler, const IpAddress& address, Uint16 port)
    {
        create(handler);

        m_peerPort    = port;
        m_peerAddress = address;
    }

    Socket::State TcpSocket::receive(void* buffer, std::size_t size, std::size_t* received, Socket::Error* error)
    {
        if(m_state == Socket::State::Connected && buffer && size)
        {
            m_state = prv::SocketImpl::receive(m_handler, buffer, size, received, error);

            return m_state;
        }

        return Socket::State::NotConnected;
    }

    Uint16 TcpSocket::getPeerPort() const
    {
        return m_peerPort;
    }

    const IpAddress& TcpSocket::getPeerAddress() const
    {
        return m_peerAddress;
    }
}