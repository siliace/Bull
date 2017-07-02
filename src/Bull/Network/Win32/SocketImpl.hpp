#ifndef BULL_NETWORK_WIN32_SOCKETIMPL_HPP
#define BULL_NETWORK_WIN32_SOCKETIMPL_HPP

#include <winsock2.h>

#include <Bull/Network/NetProtocol.hpp>
#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketImpl
        {
        public:

            static constexpr SocketHandler InvalidHandler = INVALID_SOCKET;

            /*! \brief Accept an incoming connection
             *
             * \param handler The socket to use to accept a client
             * \param ip      The IpAddress of the accepted client
             * \param port    The remote port used by the client
             *
             * \return The SocketHandler of the accepted client
             *
             */
            static SocketHandler accept(SocketHandler handler, IpAddress& ip, Socket::Port& port);

            /*! \brief Bind a SocketHandler to an IpAddress and a port to listen
             *
             * \param handler The SocketHandler
             * \param address The IpAddress to listen
             * \param port    The local port to bind
             *
             * \return True if the SocketHandler was bound successfully
             *
             */
            static bool bind(SocketHandler handler, const IpAddress& address, Socket::Port port);

            /*! \brief Create a SocketHandler
             *
             * \param protocol The protocol to used by the socket
             * \param type     The type of socket to create
             *
             * \return The created SocketHandler
             *
             */
            static SocketHandler create(NetProtocol protocol, Socket::Type type);

            /*! \brief Close a socket
             *
             * \param handler The socket to close
             *
             */
            static void close(SocketHandler handler);

            /*! \brief Start to listen the bound port
             *
             * \param handler The SocketHandler start to listen
             * \param limit   The maximum of connection simultaneous
             *
             * \return True if the socket now listen on a port
             *
             */
            static bool listen(SocketHandler handler, unsigned int limit);

            /*! \brief Set the blocking mode of a socket
             *
             * \param handler  The SocketHandler
             * \param blocking True to enable the blocking mode
             *
             */
            static void setBlocking(SocketHandler handler, bool blocking);

        private:

            static int translateSocketType(Socket::Type type);

            static int translateProtocol(NetProtocol protocol);
        };
    }
}

#endif // BULL_NETWORK_WIN32_SOCKETIMPL_HPP
