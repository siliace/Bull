#include <Bull/Network/Socket/TcpSocketStream.hpp>

namespace Bull
{
    TcpSocketStream::TcpSocketStream(TcpClient& client) :
        m_client(client)
    {
        /// Nothing
    }

    std::size_t TcpSocketStream::read(void* data, std::size_t size)
    {
        std::size_t received = 0;

        if(m_client.isConnected())
        {
            m_client.receive(data, size, received);
        }

        return received;
    }

    std::size_t TcpSocketStream::write(const void* data, std::size_t size)
    {
        std::size_t sent = 0;

        if(m_client.isConnected())
        {
            m_client.send(data, size, sent);
        }

        return sent;
    }

    std::size_t TcpSocketStream::setCursor(std::size_t position)
    {
        return 0;
    }

    std::size_t TcpSocketStream::getCursor() const
    {
        return 0;
    }

    std::size_t TcpSocketStream::getSize() const
    {
        return m_client.getPendingLength();
    }
}