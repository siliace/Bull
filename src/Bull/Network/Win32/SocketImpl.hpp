#ifndef BULL_NETWORK_WIN32_SOCKETIMPL_HPP
#define BULL_NETWORK_WIN32_SOCKETIMPL_HPP

#include <winsock2.h>

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
            static SocketHandler accept(SocketHandler handler, IpAddress& ip, NetPort& port);

            /*! \brief Bind a SocketHandler to an IpAddress and a port to listen
             *
             * \param handler The SocketHandler
             * \param address The IpAddress to listen
             * \param port    The local port to bind
             *
             * \return True if the SocketHandler was bound successfully
             *
             */
            static bool bind(SocketHandler handler, const IpAddress& address, NetPort port);

            /*! \brief Close a socket
             *
             * \param handler The socket to close
             *
             */
            static void close(SocketHandler handler);

            /*! \brief Connect the socket to a remote host
             *
             * \param handler The socket to connect
             * \param address The address of the remote host to connect
             * \param port    The port of the remote host to use
             *
             * \return True if the socket is connected
             *
             */
            static bool connect(SocketHandler handler, const IpAddress& address, NetPort port);

            /*! \brief Create a SocketHandler
             *
             * \param protocol The protocol to used by the socket
             * \param type     The type of socket to create
             *
             * \return The created SocketHandler
             *
             */
            static SocketHandler create(NetProtocol protocol, SocketType type);

            /*! \brief
             *
             * \return
             *
             */
            static SocketState lastError();

            /*! \brief Start to listen the bound port
             *
             * \param handler The SocketHandler start to listen
             * \param limit   The maximum of connection simultaneous
             *
             * \return True if the socket now listen on a port
             *
             */
            static bool listen(SocketHandler handler, unsigned int limit);

            /*! \brief
             *
             * \param handler
             * \param data
             * \param length
             *
             * \return
             *
             */
            static Index receive(SocketHandler handler, void* data, Index length);

            /*! \brief
             *
             * \param handler
             * \param from
             * \param port
             * \param data
             * \param length
             *
             * \return
             *
             */
            static Index receiveFrom(SocketHandler handler, void* data, Index length, IpAddress& from, NetPort& port);

            /*! \brief
             *
             * \param handler
             * \param data
             * \param length
             *
             * \return
             *
             */
            static Index send(SocketHandler handler, const void* data, Index length);

            /*! \brief
             *
             * \param handler
             * \param host
             * \param data
             * \param length
             *
             * \return
             *
             */
            static Index sendTo(SocketHandler handler, const void* data, Index length, const IpAddress& to, NetPort port);

            /*! \brief Set the blocking mode of a socket
             *
             * \param handler  The SocketHandler
             * \param blocking True to enable the blocking mode
             *
             */
            static void setBlocking(SocketHandler handler, bool blocking);

        private:

            /*! \brief
             *
             * \param type
             *
             * \return
             *
             */
            static int translateSocketType(SocketType type);

            /*! \brief
             *
             * \param type
             *
             * \return
             *
             */
            static int translateProtocol(NetProtocol protocol);
        };
    }
}

#endif // BULL_NETWORK_WIN32_SOCKETIMPL_HPP
