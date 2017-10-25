#ifndef BULL_NETWORK_UDPSOCKET_HPP
#define BULL_NETWORK_UDPSOCKET_HPP

#include <Bull/Network/Socket.hpp>

namespace Bull
{
    struct BULL_NETWORK_API UdpSocket : public Socket
    {
        static constexpr unsigned short MaxDatagramSize = 65507;

        /*! \brief Default constructor
         *
         */
        UdpSocket();

        /*! \brief Bind the UdpSocket to a Port
         *
         * \param port    The port the bind
         * \param address The host bind
         *
         * \return The new state of the UdpSocket
         *
         */
        SocketState bind(Socket::Port port, const IpAddress& address = IpAddress::AnyIpv4);

        /*! \brief Unbind the UdpSocket
         *
         */
        void unbind();

        /*! \brief Receive data from a remote host
         *
         * \param data          The buffer to fill with received data
         * \param length        The length of data
         * \param received      The amount of bytes received
         * \param remoteAddress The IpAddress of the remote host
         * \param remotePort    The Port of the remote host
         *
         * \return The new state of the UdpSocket
         *
         */
        SocketState receive(void* data, Index length, Index& received, IpAddress& remoteAddress, Socket::Port& remotePort);

        /*! \brief Send data to a remote host
         *
         * \param data          Data to send
         * \param length        The length of data
         * \param remoteAddress The IpAddress of the remote host
         * \param remotePort    The Port of the remote host
         *
         * \return The new state of the UdpSocket
         *
         */
        SocketState send(const void* data, Index length, const IpAddress& remoteAddress, Socket::Port remotePort);
    };
}

#endif // BULL_NETWORK_UDPSOCKET_HPP
