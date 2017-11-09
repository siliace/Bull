#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>
#include <Bull/Network/Socket/TcpClientImpl.hpp>

namespace Bull
{
    TcpClient::TcpClient() :
        Socket(SocketType_Tcp)
    {
        /// Nothing
    }

    TcpClient::~TcpClient()
    {
        disconnect();
    }

    SocketState TcpClient::connect(const IpAddressWrapper& address, NetPort port)
    {
        if(address.isValid() && port != NetPort_Any && Socket::create(address.getProtocol()))
        {
            m_impl = std::make_unique<prv::TcpClientImpl>(getImpl());

            if(m_impl->connect(address, port))
            {
                return SocketState();
            }
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    SocketState TcpClient::connect(const IpAddressWrapper& address, NetPort port, const Time& timeout, const Time& pause)
    {
        if(address.isValid() && port != NetPort_Any)
        {
            Clock clock;
            clock.start();

            do
            {
                if(connect(address, port))
                {
                    return SocketState();
                }

                Thread::sleep(pause);
            }while(clock.getElapsedTime() < timeout);
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    bool TcpClient::isConnected() const
    {
        return m_impl != nullptr;
    }

    void TcpClient::disconnect()
    {
        close();
        m_impl.reset();
        m_hostPort = NetPort_Any;
        m_hostAddress = IpAddressV4::None;
    }

    SocketState TcpClient::send(const void* data, std::size_t length, std::size_t& sent)
    {
        if(isConnected() && data && length)
        {
            std::size_t blockSent = 0;
            const unsigned char* ptr = reinterpret_cast<const unsigned char*>(data);

            for(std::size_t i = 0; i < length; i += blockSent)
            {
                if(!m_impl->send(ptr + i, length, blockSent))
                {
                    return SocketState(prv::SocketImpl::getLastError());
                }

                sent += blockSent;
            }

            return SocketState();
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    SocketState TcpClient::receive(void* data, std::size_t length, std::size_t& received)
    {
        if(isConnected() && data && length && m_impl->reveive(data, length, received))
        {
            return SocketState();
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    NetPort TcpClient::getRemotePort() const
    {
        if(isConnected())
        {
            return m_hostPort;
        }

        return NetPort_Any;
    }

    const IpAddress& TcpClient::getRemoteAddress() const
    {
        if(isConnected())
        {
            return m_hostAddress.getAddress();
        }

        return IpAddressV4::None;
    }

    bool TcpClient::create(SocketHandler handler, const IpAddressWrapper& address, NetPort port)
    {
        if(Socket::create(handler))
        {
            m_impl = std::make_unique<prv::TcpClientImpl>(getImpl());
            m_hostPort = port;
            m_hostAddress = address;

            return true;
        }

        return false;
    }
}