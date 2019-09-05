#include <thread>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>

namespace Bull
{
    TcpClient::TcpClient() :
            Socket(SocketType_Tcp)
    {
        /// Nothing
    }

    TcpClient::TcpClient(TcpClient&& right) noexcept :
            Socket(std::move(right))
    {
        std::swap(m_hostPort, right.m_hostPort);
        std::swap(m_hostAddress, right.m_hostAddress);
    }

    TcpClient::~TcpClient()
    {
        close();
    }

    TcpClient& TcpClient::operator=(TcpClient&& right) noexcept
    {
        std::swap(m_hostPort, right.m_hostPort);
        std::swap(m_hostAddress, right.m_hostAddress);

        Socket::operator=(std::move(right));

        return *this;
    }

    void TcpClient::connect(const IpAddress& address, NetPort port)
    {
        Expect(address.isValid(), Throw(InvalidParameter, "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "Invalid NetPort"));

        Socket::create(address.getProtocol());

        prv::SockAddrBuffer buffer(address, port);

        int ret = ::connect(getHandler(), buffer.getSockAddr(), buffer.getLength());

        Expect(ret == 0, Throw(InternalError, "Failed to connect to the remote host"));
    }

    void TcpClient::connect(const IpAddress& address, NetPort port, const Duration& timeout, const Duration& pause)
    {
        Expect(address.isValid(), Throw(InvalidParameter, "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "Invalid NetPort"));

        int ret;
        Clock clock;

        Socket::create(address.getProtocol());

        prv::SockAddrBuffer buffer(address, port);

        clock.start();

        do
        {
            ret = ::connect(getHandler(), buffer.getSockAddr(), buffer.getLength());

            if(ret != 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(pause.asMilliseconds())));
            }
        }while(ret != 0 && clock.getElapsedTime() < timeout);

        Expect(ret == 0, Throw(InternalError, "Failed to connect to the remote host"));
    }

    bool TcpClient::isConnected() const
    {
        return isValid();
    }

    void TcpClient::disconnect()
    {
        close();
        m_hostAddress.reset();
        m_hostPort = NetPort_Any;
    }

    size_t TcpClient::write(const ByteArray& bytes)
    {
        return send(bytes.getBuffer(), bytes.getCapacity());
    }

    std::size_t TcpClient::send(const void* data, std::size_t length)
    {
        Expect(data && length, Throw(InvalidParameter, "Invalid buffer"));
        Expect(isConnected(), Throw(LogicError, "TcpClient is not connected"));

        int sent = ::send(getHandler(), reinterpret_cast<const char*>(data), length, 0);

        Expect(sent >= 0, Throw(InternalError, "Failed to send data to the remote host"));

        return sent;
    }

    ByteArray TcpClient::read(std::size_t length)
    {
        ByteArray byteArray(length);

        std::size_t read = receive(&byteArray[0], byteArray.getCapacity());

        byteArray.resize(read);

        return byteArray;
    }

    std::size_t TcpClient::receive(void* data, std::size_t length)
    {
        Expect(data && length, Throw(InvalidParameter, "Invalid buffer"));
        Expect(isConnected(), Throw(LogicError, "TcpClient is not connected"));

        int received = ::recv(getHandler(), reinterpret_cast<char*>(data), length, 0);

        Expect(received >= 0, Throw(InternalError, "Failed to receive data from the remote host"));

        return received;
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
        Expect(isConnected(), Throw(LogicError, "TcpClient is not connected"));

        return m_hostPort;
    }

    const IpAddress& TcpClient::getRemoteAddress() const
    {
        Expect(isConnected(), Throw(LogicError, "TcpClient is not connected"));

        return *m_hostAddress;
    }

    void TcpClient::create(SocketHandler handler, std::unique_ptr<IpAddress>&& address, NetPort port)
    {
        Socket::create(handler);

        m_hostPort = port;
        m_hostAddress = std::move(address);
    }
}