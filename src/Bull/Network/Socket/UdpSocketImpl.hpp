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
            explicit UdpSocketImpl(const SocketImpl& socket);

            /*! \brief Bind the UdpSocket to a NetPort
             *
             * \param port    The NetPort to listen
             * \param address The IpAddress to listen
             *
             */
            void bind(NetPort port, const IpAddressWrapper& address);

            /*! \brief Send data to a remote host
             *
             * \param address The IpAddress of the remote host to send data
             * \param port    The NetPort of the remote host to use
             * \param data    Data to send
             * \param length  The length of data to send
             *
             * \return The amount of bytes sent
             *
             */
            std::size_t sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length) const;

            /*! \brief Receive data from a remote host
             *
             * \param address  The IpAddress of the remote host
             * \param port     The NetPort of the remote host
             * \param data     Data to receive
             * \param length   The length of data to receive
             *
             * \return The amount of bytes received
             *
             */
            std::size_t receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length) const;

        private:

            const SocketImpl& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP
