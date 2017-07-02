#ifndef BULL_NETWORK_TCPLISTENER_HPP
#define BULL_NETWORK_TCPLISTENER_HPP

#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/Socket.hpp>
#include <Bull/Network/IpAddress.hpp>

namespace Bull
{
    class TcpSocket;

    struct BULL_NETWORK_API TcpListener : public Socket
    {
        /*! \brief Default constructor
         *
         */
        TcpListener();

        /*! \brief Listen a local port
         *
         * \param port    The port to listen
         * \param backlog The maximum amount of simultaneous connections
         *
         * \return The new State of the TcpListener
         *
         */
        State listen(Port port, unsigned int backlog = 0);

        /*! \brief Listen a local port
         *
         * \param port    The port to listen
         * \param host    Hosts to accept incoming connection
         * \param backlog The maximum amount of simultaneous connections
         *
         * \return The new State of the TcpListener
         *
         */
        State listen(Port port, const IpAddress& host, unsigned int backlog = 0);

        /*! \brief Accept an incoming connection
         *
         * \param client The client to accept
         *
         * \return The new State of the TcpListenner
         *
         */
        State accept(TcpSocket& client);

        /*! \brief Accept an incoming connection
         *
         * \param client
         * \param timeout
         *
         * \return
         *
         */
        State accept(TcpSocket& client, const Time& timeout);

        /*! \brief Get the local that the TcpListener is listening
         *
         * \return The port
         *
         */
        Port getListeningPort() const;
    };
}

#endif // BULL_NETWORK_TCPLISTENER_HPP
