#ifndef BULL_TCPSOCKET_HPP
#define BULL_TCPSOCKET_HPP

#include <Bull/Core/IO/InOutStream.hpp>
#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>

namespace Bull
{
    class BULL_API TcpSocket : public Socket, public InOutStream
    {
    public:

        /*! \brief Default constructor
         *
         */
        TcpSocket();

        /*! \brief Destructor
         *
         */
        ~TcpSocket();

        /*! \brief Connect the socket to a remote host
         *
         * \param address The remote address to connect
         * \param port    The remote port to connect
         * \param timeout The connection timeout
         * \param error   A pointer to store the error
         *
         * \return The new socket state
         *
         */
        State connect(const IpAddress& address, Uint16 port, const Time& timeout = Time::Zero, Socket::Error* error = nullptr);

        /*! \brief Disconnect the socket
         *
         */
        void disconnect();

        /*! \brief Reset a TcpSocket
         *
         * \param handler The new handler
         * \param address The new peer address
         * \param port    The new port
         *
         */
        void reset(SocketHandler handler, const IpAddress& address, Uint16 port);

        /*! \brief Read data from a stream
         *
         * \param data A pointer to the memory area to fill
         * \param size The size of the memory area to fill
         *
         * \return Return the number of read bytes
         *
         */
        Uint64 read(void* data, Uint64 size);

        /*! \brief Write data into a stream
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        Uint64 write(const void* data, Uint64 size);

        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        Uint64 setCursor(Uint64 position);

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        Uint64 getCursor() const;

        /*! \brief Get the size of the stream
         *
         * \return The size of the stream
         *
         */
        Uint64 getSize() const;

        /*! \brief Get the peer port
         *
         * \return The port
         *
         */
        Uint16 getPeerPort() const;

        /*! \brief Get the peer IpAddress
         *
         * \return The IpAddress
         *
         */
        const IpAddress& getPeerAddress() const;

    private:

        Uint16    m_peerPort;
        IpAddress m_peerAddress;
    };
}

#endif // BULL_TCPSOCKET_HPP
