#ifndef BULL_NETWORK_SOCKET_TCPCLIENT_HPP
#define BULL_NETWORK_SOCKET_TCPCLIENT_HPP

#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketHandler.hpp>

namespace Bull
{
    class TcpServer;

    namespace prv
    {
        class TcpClientImpl;
    }

    class BULL_NETWORK_API TcpClient : public Socket
    {
    public:

        /*! \brief Default constructor
         *
         */
        TcpClient();

        /*! \brief Destructor
         *
         */
        ~TcpClient();

        /*! \brief Connect the TcpClient to a remote host
         *
         * \param address The IpAddress of the remote host
         * \param port    The NetPort of the remote host
         *
         * \return True if the TcpClient is connected
         *
         */
        bool connect(const IpAddress& address, NetPort port);

        bool isConnected() const;

        void disconnect();

        /*! \brief Send bytes the remote host
         *
         * \param bytes Bytes to send
         *
         * \return True if bytes were sent successfully
         *
         */
        bool send(const ByteArray& bytes);

        /*! \brief Receive bytes from from the remote host
         *
         * \param bytes Bytes received
         *
         * \return True if bytes were received successfully
         *
         */
        bool receive(ByteArray& bytes);

        /*! \brief Get the remote NetPort
         *
         * \return The NetPort
         *
         */
        NetPort getRemotePort() const;

        /*! \brief Get the remote IpAddress
         *
         * \return The IpAddress
         *
         */
        const IpAddress& getRemoteAddress() const;

    private:

        friend class TcpServer;

        /*! \brief Reset the TcpClient
         *
         * \param handler The new SocketHandler
         * \param address The new IpAddress
         * \param port    The new NetPort
         *
         */
        void reset(SocketHandler handler, const IpAddress& address, NetPort port);

    private:

        std::unique_ptr<prv::TcpClientImpl> m_impl;
        NetPort                             m_hostPort;
        IpAddress                           m_hostAddress;
    };
}

#endif // BULL_NETWORK_SOCKET_TCPCLIENT_HPP
