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
            static bool connect(SocketHandler handler, const IpAddress& address, Socket::Port port);

            /*! \brief Create a SocketHandler
             *
             * \param protocol The protocol to used by the socket
             * \param type     The type of socket to create
             *
             * \return The created SocketHandler
             *
             */
            static SocketHandler create(IpAddress::NetProtocol protocol, Socket::Type type);

            /*! \brief
             *
             * \return
             *
             */
            static Socket::State lastError();

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
            static std::size_t receive(SocketHandler handler, void* data, std::size_t length);

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
            static std::size_t receiveFrom(SocketHandler handler, void* data, std::size_t length, IpAddress& from, Socket::Port& port);

            /*! \brief
             *
             * \param handler
             * \param data
             * \param length
             *
             * \return
             *
             */
            static std::size_t send(SocketHandler handler, const void* data, std::size_t length);

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
            static std::size_t sendTo(SocketHandler handler, const IpAddress& to, Socket::Port port, const void* data, std::size_t length);

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
            static int translateSocketType(Socket::Type type);

            /*! \brief
             *
             * \param type
             *
             * \return
             *
             */
            static int translateProtocol(IpAddress::NetProtocol protocol);
        };
    }
}

#endif // BULL_NETWORK_WIN32_SOCKETIMPL_HPP
