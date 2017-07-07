#ifndef BULL_NETWORK_TCPSOCKET_HPP
#define BULL_NETWORK_TCPSOCKET_HPP

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/Socket.hpp>

namespace Bull
{
    class Time;
    class IpAddress;
    class TcpListener;

    class BULL_NETWORK_API TcpSocket : public Socket
    {
    public:

        /*! \brief Default constructor
         *
         */
        TcpSocket();

        /*! \brief Connect the TcpSocket to a remote host
         *
         * \param address The IpAddress to connect
         * \param port    The port of the remote host to connect
         *
         * \return The new State of the TcpSocket
         *
         */
        State connect(const IpAddress& address, Port port);

        /*! \brief Connect the TcpSocket to a remote host
         *
         * \param address The IpAddress to connect
         * \param port    The port of the remote host to connect
         * \param timeout The time to keep trying to connect to the host
         *
         * \return The new State of the TcpSocket
         *
         */
        State connect(const IpAddress& address, Port port, const Time& timeout);

        /*! \brief Disconnect the TcpSocket from the remote host
         *
         */
        void disconnect();

        /*! \brief Send data to the remote host
         *
         * \param data   Data to send
         * \param length The length of data to send
         * \param sent   The amount of bytes sent through the TcpSocket
         *
         * \return The new State of the TcpSocket
         *
         */
        State send(const void* data, std::size_t length, std::size_t* sent = nullptr);

        /*! \brief Send data to the remote host
         *
         * \param data   The buffer to fill
         * \param length The length of the buffer to fill
         *
         * \return The new State of the TcpSocket
         *
         */
        State receive(void* data, std::size_t length);

    private:

        friend class TcpListener;

        /*! \brief Create a Socket from an handler
         *
         * \param handler The handler to use
         *
         */
        void reset(SocketHandler handler, const IpAddress& address, Socket::Port port);

    private:

        Port      m_remotePort;
        IpAddress m_remoteAddress;
    };
}

#endif // BULL_NETWORK_TCPSOCKET_HPP
