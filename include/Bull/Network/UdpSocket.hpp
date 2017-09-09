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

        /*! \brief
         *
         * \param port
         * \param address
         *
         * \return
         *
         */
        State bind(Socket::Port port, const IpAddress& address = IpAddress::AnyIpv4);

        /*! \brief
         *
         */
        void unbind();

        /*! \brief
         *
         * \param data
         * \param length
         * \param remoteAddress
         * \param remotePort
         *
         * \return
         *
         */
        State receive(void* data, Index length, Index& received, IpAddress& remoteAddress, Socket::Port& remotePort);

        /*! \brief
         *
         * \param remoteAddress
         * \param remotePort
         * \param data
         * \param length
         *
         * \return
         *
         */
        State send(const IpAddress& remoteAddress, Socket::Port remotePort, const void* data, Index length);
    };
}

#endif // BULL_NETWORK_UDPSOCKET_HPP
