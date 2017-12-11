#ifndef BULL_NETWORK_SOCKET_UDPSOCKET_HPP
#define BULL_NETWORK_SOCKET_UDPSOCKET_HPP

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketState.hpp>

namespace Bull
{
    namespace prv
    {
        class UdpSocketImpl;
    }

    class BULL_NETWORK_API UdpSocket : public Socket
    {
    public:

        /*! \brief Default constructor
         *
         */
        UdpSocket();

        /*! \brief Constructor by movement
         *
         * \param move The UdpSocket to move
         *
         */
        UdpSocket(UdpSocket&& move) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~UdpSocket();

        /*! \brief Basic assignment operator by movement
         *
         * \param move The UdpSocket to move
         *
         * \return This
         *
         */
        UdpSocket& operator=(UdpSocket&& move) noexcept = default;

        /*! \brief Bind the UdpSocket to a NetPort
         *
         * \param port    The NetPort to listen
         * \param address The IpAddress to listen
         *
         * \return The new SocketState
         *
         */
        SocketState bind(NetPort port, const IpAddressWrapper& address = IpAddressV4::Any);

        /*! \brief Tell whether the UdpSocket is bound
         *
         * \return True if the UdpSocket is bound
         *
         */
        bool isBound() const;

        /*! \brief Unbind the UdpSocket
         *
         */
        void unbind();

        /*! \brief Send data to a remote host
         *
         * \param address The IpAddress of the remote host to send data
         * \param port    The NetPort of the remote host to use
         * \param data    Data to send
         * \param length  The length of data to send
         * \param sent    The amount of bytes sent
         *
         * \return The new SocketState
         *
         */
        SocketState sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const;

        /*! \brief Receive data from a remote host
         *
         * \param address  The IpAddress of the remote host
         * \param port     The NetPort of the remote host
         * \param data     Data to receive
         * \param length   The length of data to receive
         * \param received The amount of bytes received
         *
         * \return The new SocketState
         *
         */
        SocketState receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const;

    private:

        std::unique_ptr<prv::UdpSocketImpl> m_impl;
    };
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKET_HPP
