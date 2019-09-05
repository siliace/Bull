#ifndef BULL_NETWORK_SOCKET_TCPSERVER_HPP
#define BULL_NETWORK_SOCKET_TCPSERVER_HPP

#include <Bull/Core/Time/Duration.hpp>

#include <Bull/Network/Address/IpAddressV4.hpp>
#include <Bull/Network/Socket/TcpClient.hpp>

namespace Bull
{
    class BULL_NETWORK_API TcpServer : public Socket
    {
    public:

        static constexpr int UnlimitedBacklog = -1;

    public:

        /** \brief Default constructor
         *
         */
        TcpServer();

        /** \brief Constructor by movement
         *
         * \param right The TcpServer to move
         *
         */
        TcpServer(TcpServer&& right) noexcept;

        /** \brief Destructor
         *
         */
        ~TcpServer();

        /** \brief Basic assignment operator by movement
         *
         * \param right The TcpServer to move
         *
         * \return This
         *
         */
        TcpServer& operator=(TcpServer&& right) noexcept;

        /** \brief Start to listen a NetPort
         *
         * \param port    The NetPort to listen
         * \param host    The host to listen
         * \param backlog The number of simultaneous active connection on the TcpServer
         *
         */
        void listen(NetPort port, const IpAddress& host = IpAddressV4::Any, int backlog = UnlimitedBacklog);

        /** \brief Tell whether the TcpServer is listening a NetPort
         *
         * \return True if the TcpServer is listening
         *
         */
        bool isListening() const;

        /** \brief Accept an incoming connection
         *
         * \return The client accepted
         *
         */
        TcpClient accept();

        /** \brief Disconnect the TcpServer
         *
         */
        void disconnect();

        /** \brief The number of simultaneous active connection on the TcpServer
         *
         * \return The number of simultaneous active connection
         *
         */
        int getBacklog() const;

        /** \brief Get the NetPort listened by the TcpServer
         *
         * \return The NetPort
         *
         */
        NetPort getPort() const;

    private:

        NetPort m_port;
        int m_backlog;
    };
}

#endif // BULL_NETWORK_SOCKET_TCPSERVER_HPP
