#ifndef BULL_NETWORK_SOCKET_TCPSERVER_HPP
#define BULL_NETWORK_SOCKET_TCPSERVER_HPP

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Socket/Socket.hpp>

namespace Bull
{
    class TcpClient;

    namespace prv
    {
        class TcpServerImpl;
    }

    class BULL_NETWORK_API TcpServer : public Socket
    {
    public:

        /*! \brief Default constructor
         *
         */
        TcpServer();

        /*! \brief Destructor
         *
         */
        ~TcpServer();

        /*! \brief Start to listen a NetPort
         *
         * \param port    The NetPort
         * \param host    The host to listen
         * \param backlog The number of simultaneous active connection on the TcpServer
         *
         * \return True if the TcpServer is listening the NetPort
         *
         */
        bool listen(NetPort port, const IpAddressWrapper& host = IpAddressV4::Any, int backlog = -1);

        /*! \brief Tell whether the TcpServer is listening a NetPort
         *
         * \return True if the TcpServer is listening
         *
         */
        bool isListening() const;

        /*! \brief Accept an incoming connection
         *
         * \param client The client to accept
         *
         * \return True if the client was accepted successfully
         *
         */
        bool accept(TcpClient& client);

        /*! \brief Accept an incoming connection
         *
         * \param client  The client to accept
         * \param timeout The timeout of before the function fail
         * \param pause   The time between two try
         *
         * \return True if the client was accepted successfully
         *
         */
        bool accept(TcpClient& client, const Time& timeout, const Time& pause = Time::milliseconds(20.f));

        /*! \brief Disconnect the TcpServer
         *
         */
        void disconnect();

        /*! \brief The number of simultaneous active connection on the TcpServer
         *
         * \return The number of simultaneous active connection
         *
         */
        int getBacklog() const;

        /*! \brief Get the NetPort listened by the TcpServer
         *
         * \return The NetPort
         *
         */
        NetPort getPort() const;

    private:

        std::unique_ptr<prv::TcpServerImpl> m_impl;
        NetPort                             m_port;
        int                                 m_backlog;
    };
}

#endif // BULL_NETWORK_SOCKET_TCPSERVER_HPP
