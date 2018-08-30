#include <thread>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
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

    TcpClient::TcpClient(TcpClient&& move) noexcept :
        Socket(std::move(move))
    {
        std::swap(m_impl, move.m_impl);
        std::swap(m_hostPort, move.m_hostPort);
        std::swap(m_hostAddress, move.m_hostAddress);
    }

    TcpClient::~TcpClient()
    {
        close();
    }

    TcpClient& TcpClient::operator=(TcpClient&& move) noexcept
    {
        std::swap(m_impl, move.m_impl);
        std::swap(m_hostPort, move.m_hostPort);
        std::swap(m_hostAddress, move.m_hostAddress);

        Socket::operator=(std::move(move));

        return *this;
    }

    void TcpClient::connect(const IpAddressWrapper& address, NetPort port)
    {
        Expect(address.isValid(), Throw(InvalidParameter, "TcpClient::connect", "Invalid IpAddress"));
        Expect(port != NetPort_Any, Throw(InvalidParameter, "TcpClient::connect", "Invalid NetPort"));

        Socket::create(address.getProtocol());

        m_impl = std::make_unique<prv::TcpClientImpl>(getImpl());

        m_impl->connect(address, port);
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
        return send(bytes.getBuffer(), bytes.getCapacity());
    }

    std::size_t TcpClient::send(const void* data, std::size_t length)
    {
        Expect(data && length, Throw(InvalidParameter, "TcpClient::send", "Invalid buffer"));
        Expect(isConnected(), Throw(LogicError, "TcpClient::send", "TcpClient is not connected"));

        return m_impl->send(data, length);
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
        Expect(data && length, Throw(InvalidParameter, "TcpClient::send", "Invalid buffer"));
        Expect(isConnected(), Throw(LogicError, "TcpClient::send", "TcpClient is not connected"));

        return m_impl->receive(data, length);
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
        Expect(isConnected(), Throw(LogicError, "TcpClient::send", "TcpClient is not connected"));

        return m_hostPort;
    }

    const IpAddress& TcpClient::getRemoteAddress() const
    {
        Expect(isConnected(), Throw(LogicError, "TcpClient::send", "TcpClient is not connected"));

        return m_hostAddress.getAddress();
    }

    void TcpClient::create(SocketHandler handler, const IpAddressWrapper& address, NetPort port)
    {
        Socket::create(handler);

        m_hostPort    = port;
        m_hostAddress = address;
        m_impl        = std::make_unique<prv::TcpClientImpl>(getImpl());
    }
}