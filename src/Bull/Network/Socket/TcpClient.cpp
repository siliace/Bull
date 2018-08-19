#include <thread>

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

    SocketState TcpClient::connect(const IpAddressWrapper& address, NetPort port, const Duration& timeout, const Duration& pause)
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

                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<unsigned int>(pause.asMilliseconds())));
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

    size_t TcpClient::write(const ByteArray& bytes)
    {
        std::size_t sent;

        if(!send(bytes.getBuffer(), bytes.getCapacity(), sent))
        {
            return 0;
        }

        return sent;
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

    ByteArray TcpClient::read(std::size_t length)
    {
        std::size_t read;
        ByteArray byteArray(length);

        if(!receive(&byteArray[0], byteArray.getCapacity(), read))
        {
            return ByteArray();
        }

        byteArray.resize(read);

        return byteArray;
    }

    SocketState TcpClient::receive(void* data, std::size_t length, std::size_t& received)
    {
        if(isConnected() && data && length && m_impl->reveive(data, length, received))
        {
            return SocketState();
        }

        return SocketState(prv::SocketImpl::getLastError());
    }

    void TcpClient::flush()
    {
        /// Since TCP protocol is stream based and not message based, flushing it does not make any sens
    }

    void TcpClient::skip(std::size_t length)
    {
        read(length);
    }

    bool TcpClient::isAtEnd() const
    {
        return !isConnected();
    }

    size_t TcpClient::getSize() const
    {
        return getPendingLength();
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
            m_hostPort    = port;
            m_hostAddress = address;
            m_impl        = std::make_unique<prv::TcpClientImpl>(getImpl());

            return true;
        }

        return false;
    }
}