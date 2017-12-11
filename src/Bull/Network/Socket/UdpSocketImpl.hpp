#ifndef BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP
#define BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class UdpSocketImpl : public NonCopyable
        {
        public:

            /*! \brief Constructor
             *
             * \param socket The SocketImpl to use
             *
             */
            explicit UdpSocketImpl(const std::unique_ptr<SocketImpl>& socket);

            /*! \brief Bind the UdpSocket to a NetPort
             *
             * \param port    The NetPort to listen
             * \param address The IpAddress to listen
             *
             * \return True if the UdpSocket was bound successfully
             *
             */
            bool bind(NetPort port, const IpAddressWrapper& address);

            /*! \brief Send data to a remote host
             *
             * \param address The IpAddress of the remote host to send data
             * \param port    The NetPort of the remote host to use
             * \param data    Data to send
             * \param length  The length of data to send
             * \param sent    The amount of bytes sent
             *
             * \return True if the data were sent successfully
             *
             */
            bool sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const;

            /*! \brief Receive data from a remote host
             *
             * \param address  The IpAddress of the remote host
             * \param port     The NetPort of the remote host
             * \param data     Data to receive
             * \param length   The length of data to receive
             * \param received The amount of bytes received
             *
             * \return True if the data were received successfully
             *
             */
            bool receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const;

        private:

            const std::unique_ptr<SocketImpl>& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP
