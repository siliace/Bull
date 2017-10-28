#ifndef BULL_NETWORK_TCPSOCKET_HPP
#define BULL_NETWORK_TCPSOCKET_HPP

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
        SocketState connect(const IpAddress& address, NetPort port);

        /*! \brief Connect the TcpSocket to a remote host
         *
         * \param address The IpAddress to connect
         * \param port    The port of the remote host to connect
         * \param timeout The time to keep trying to connect to the host
         *
         * \return The new State of the TcpSocket
         *
         */
        SocketState connect(const IpAddress& address, NetPort port, const Time& timeout);

        /*! \brief Disconnect the TcpSocket from the remote host
         *
         */
        void disconnect();

        /*! \brief Check whether the TcpSocket is connected to a remote host
         *
         * \return True if the TcpSocket is connected
         * 
         */
        bool isConnected() const;

        /*! \brief Send data to the remote host
         *
         * \param data   Data to send
         * \param length The length of data to send
         * \param sent   The amount of bytes sent through the TcpSocket
         *
         * \return The new State of the TcpSocket
         *
         */
        SocketState send(const void* data, Index length, Index& sent);

        /*! \brief Send data to the remote host
         *
         * \param data     The buffer to fill
         * \param length   The length of the buffer to fill
         * \param received The amount of bytes received througth the socket
         *
         * \return The new State of the TcpSocket
         *
         */
        SocketState receive(void* data, Index length, Index& received);

    private:

        friend class TcpListener;

        /*! \brief Create a Socket from an handler
         *
         * \param handler The handler to use
         *
         */
        void reset(SocketHandler handler, const IpAddress& address, NetPort port);

    private:

        /*! \brief Update the state of the TcpSocket
         *
         * \param state The new state of the TcpSocket
         *
         * \return This
         */
        TcpSocket& updateState(SocketState state);

        SocketState m_state;
        NetPort        m_remotePort;
        IpAddress   m_remoteAddress;
    };
}

#endif // BULL_NETWORK_TCPSOCKET_HPP
