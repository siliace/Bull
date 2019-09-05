#ifndef BULL_NETWORK_SOCKET_UDPSOCKET_HPP
#define BULL_NETWORK_SOCKET_UDPSOCKET_HPP

#include <Bull/Network/Address/IpAddressV4.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/Datagram.hpp>
#include <Bull/Network/Socket/Socket.hpp>

namespace Bull
{
    struct BULL_NETWORK_API UdpSocket : public Socket
    {
        /** \brief Default constructor
         *
         */
        UdpSocket();

        /** \brief Constructor by movement
         *
         * \param move The UdpSocket to move
         *
         */
        UdpSocket(UdpSocket&& move) noexcept = default;

        /** \brief Destructor
         *
         */
        ~UdpSocket();

        /** \brief Basic assignment operator by movement
         *
         * \param move The UdpSocket to move
         *
         * \return This
         *
         */
        UdpSocket& operator=(UdpSocket&& move) noexcept = default;

        /** \brief Bind the UdpSocket to a NetPort
         *
         * \param port The NetPort to listen
         * \param host The IpAddress to listen
         *
         */
        void bind(NetPort port, const IpAddress& host = IpAddressV4::Any);

        /** \brief Tell whether the UdpSocket is bound
         *
         * \return True if the UdpSocket is bound
         *
         */
        bool isBound() const;

        /** \brief Unbind the UdpSocket
         *
         */
        void unbind();

        /** \brief Send data to a remote host
         *
         * \param address The IpAddress of the remote host to send data
         * \param port    The NetPort of the remote host to use
         * \param data    Data to send
         * \param length  The length of data to send
         *
         * \return The amount of bytes sent
         *
         */
        std::size_t sendTo(const IpAddress& address, NetPort port, const void* data, std::size_t length) const;

        Datagram receiveFrom() const;

        /** \brief Receive data from a remote host
         *
         * \param length The length of data to receive
         *
         */
        Datagram receiveFrom(std::size_t length) const;
    };
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKET_HPP
