#ifndef BULL_TCPSOCKET_HPP
#define BULL_TCPSOCKET_HPP

#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>

namespace Bull
{
    class BULL_API TcpSocket : public Socket
    {
    public:

        /*! @brief Default constructor
         *
         */
        TcpSocket();

        /*! @brief Destructor
         *
         */
        ~TcpSocket();

        /*! @brief Connect the socket to a remote host
         *
         * @param address The remote address to connect
         * @param port    The remote port to connect
         * @param timeout The connection timeout
         * @param error   A pointer to store the error
         *
         * @return The new socket state
         *
         */
        State connect(const IpAddress& address, Uint16 port, const Time& timeout = Time::Zero, Socket::Error* error = nullptr);

        /*! @brief Disconnect the socket
         *
         */
        void disconnect();

        /*! @brief Reset a TcpSocket
         *
         * @param handler The new handler
         * @param address The new peer address
         * @param port    The new port
         *
         */
        void reset(SocketHandler handler, const IpAddress& address, Uint16 port);

        /*! @brief Receive the data available
         *
         * @param buffer   The buffer to fill with received data
         * @param size     The size of the buffer
         * @param reveived A pointer to store how many bytes has been read
         * @param error    A pointer to store the error
         *
         * @return The state of the socket
         *
         */
        Socket::State receive(void* buffer, std::size_t size, std::size_t* received = nullptr, Socket::Error* error = nullptr);

        /*! @brief Get the peer port
         *
         * @return The port
         *
         */
        Uint16 getPeerPort() const;

        /*! @brief Get the peer IpAddress
         *
         * @return The IpAddress
         *
         */
        const IpAddress& getPeerAddress() const;

    private:

        Uint16    m_peerPort;
        IpAddress m_peerAddress;
    };
}

#endif // BULL_TCPSOCKET_HPP
