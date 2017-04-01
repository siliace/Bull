#ifndef BULL_SOCKETIMPL_HPP
#define BULL_SOCKETIMPL_HPP

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>
#include <Bull/Network/SocketHandler.hpp>
#include <Bull/Network/Unix/SystemSocket.hpp>

namespace Bull
{
    namespace prv
    {
        struct SocketImpl
        {
            static constexpr SocketHandler InvalidHandler = -1;

            /*! @brief Accept an incoming connection
             *
             * @param socket        The listener socket
             * @param clientAddress The accepted IpAddress
             * @param port          The port of the accepted IpAddress
             * @param error         A pointer to store the error
             *
             * @return The accepted SocketHandler
             *
             */
            static SocketHandler accept(SocketHandler socket, IpAddress& clientAddress, Uint16& clientPort, Socket::Error* error);

            /*! @brief Create a SocketHandler
             *
             * @param protocol The protocol used by the socket
             * @param type     The type of socket to create
             *
             * @return The created SocketHandler
             *
             */
            static SocketHandler create(NetProtocol protocol, Socket::Type type);

            /*! @brief Connect a socket the a remote host
             *
             * @param socket The socket
             * @param remote The IpAddress of the remote host
             * @param port
             * @param error  A pointer to store the error
             *
             * @return The new state of the socket
             *
             */
            static Socket::State connect(SocketHandler socket, const IpAddress& remote, Uint16 port, Socket::Error* error);

            /*! @brief Close a socket
             *
             * @param socket The socket to close
             *
             */
            static void close(SocketHandler socket);

            /*! @brief Enable or disable the blocking mode
             *
             * @param socket The socket to change blocking mode
             * @param enable True to enable
             *
             */
            static void enableBlockingMode(SocketHandler socket, bool enable);

            /*! @brief Listen a port
             *
             * @param socket  The socket to bind to the port
             * @param address The IpAddress to listen
             * @param port    The port to listen
             * @param queueLength The maximum of connection accepted
             * @param error   A pointer to store the error
             *
             * @return The new state of the socket
             *
             */
            static Socket::State listen(SocketHandler socket, const IpAddress& address, Uint16 port, std::size_t queueLength, Socket::Error* error);

            /*! @brief Convert a Bull::NetProtocol to a AF value
             *
             * @param protocol The protocol to convert
             *
             * @return The equivalent AF value
             *
             */
            static int netProtocolToAF(NetProtocol protocol);

            /*! @brief Receive the data available
             *
             * @param socket   The socket to read on
             * @param buffer   The buffer to fill with received data
             * @param size     The size of the buffer
             * @param reveived A pointer to store how many bytes has been read
             * @param error    A pointer to store the error
             *
             * @return The state of the socket
             *
             */
            static Socket::State receive(SocketHandler socket, void* buffer, std::size_t size, std::size_t* received, Socket::Error* error);

            /*! @brief Convert a Bull::Socket::Type to a SOCK value
             *
             * @param type The type to convert
             *
             * @return The equivalent SOCK value
             *
             */
            static int socketTypeToSock(Socket::Type type);
        };
    }
}

#endif // BULL_SOCKETIMPL_HPP
