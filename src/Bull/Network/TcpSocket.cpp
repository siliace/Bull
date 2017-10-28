#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/TcpSocket.hpp>
#include <Bull/Network/SocketImpl.hpp>

namespace Bull
{
    TcpSocket::TcpSocket() :
        Socket(SocketType_Tcp),
        m_state(SocketState_Disconnected),
        m_remotePort(NetPort_Any),
        m_remoteAddress(IpAddress::None)
    {
        /// Nothing
    }

    SocketState TcpSocket::connect(const IpAddress& address, NetPort port)
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

            return SocketState_Ready;
        }

        return SocketState_Disconnected;
    }

    SocketState TcpSocket::connect(const IpAddress& address, NetPort port, const Time& timeout)
    {
        SocketState state;
        Clock       timer;

        timer.start();

        do
        {
            Thread::sleep(Time::milliseconds(10.f));
            state = connect(address, port);
        }while(timer.getElapsedTime() < timeout && state != SocketState_Ready);

        return state;
    }

    void TcpSocket::disconnect()
    {
        close();

        m_remotePort    = NetPort_Any;
        m_remoteAddress = IpAddress::None;
    }

    bool TcpSocket::isConnected() const
    {
        return getHandler() != prv::SocketImpl::InvalidHandler;
    }

    SocketState TcpSocket::send(const void* data, Index length, Index& sent)
    {
        if(data && length)
        {
            SocketState state;
            Index result = 0;
            for(sent = 0; sent < length; sent += result)
            {
                result = prv::SocketImpl::send(getHandler(), data, length);

                if(result <= 0)
                {
                    state = prv::SocketImpl::lastError();

                    if(state == SocketState_NotReady && sent > 0)
                    {
                        return SocketState_Partial;
                    }

                    return state;
                }
            }

            return SocketState_Ready;
        }
        else
        {
            updateState(SocketState_Error);
        }

        return m_state;
    }

    SocketState TcpSocket::receive(void* data, Index length, Index& received)
    {
        received = 0;

        if(!data || length)
        {
            Index result = prv::SocketImpl::receive(getHandler(), data, length);

            if(result > 0)
            {
                received = result;

                updateState(SocketState_Ready);
            }
            else if(result == 0)
            {
                updateState(SocketState_Disconnected);
            }
            else
            {
                updateState(prv::SocketImpl::lastError());
            }
        }

        return m_state;
    }

    void TcpSocket::reset(SocketHandler handler, const IpAddress& address, NetPort port)
    {
        if(getHandler() != prv::SocketImpl::InvalidHandler)
        {
            disconnect();
        }

        Socket::reset(handler);

        m_remotePort    = port;
        m_state         = SocketState_Ready;
        m_remoteAddress = address;
    }

    TcpSocket& TcpSocket::updateState(SocketState state)
    {
        m_state = state;

        return (*this);
    }
}