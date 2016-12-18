#include <iostream>

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
            enableBlockingMode(false);

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

    Uint64 TcpSocket::read(void* data, Uint64 size)
    {
        return 0;
    }

    Uint64 TcpSocket::write(const void* data, Uint64 size)
    {
        return 0;
    }

    Uint64 TcpSocket::setCursor(Uint64 position)
    {
        return position;
    }

    Uint64 TcpSocket::getCursor() const
    {
        return 0;
    }

    Uint64 TcpSocket::getSize() const
    {
        return 0;
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
