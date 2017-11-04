#ifndef BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP
#define BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP

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

            /*! \brief
             *
             * \param address
             * \param port
             *
             * \return
             *
             */
            bool bind(NetPort port, const IpAddressWrapper& address);

            /*! \brief
             *
             * \param address
             * \param port
             * \param data
             * \param length
             * \param sent
             *
             * \return
             *
             */
            bool sendTo(const IpAddressWrapper& address, NetPort port, const void* data, std::size_t length, std::size_t& sent) const;

            /*! \brief
             *
             * \param address
             * \param port
             * \param data
             * \param length
             * \param received
             *
             * \return
             *
             */
            bool receiveFrom(IpAddressWrapper& address, NetPort& port, void* data, std::size_t length, std::size_t& received) const;

        private:

            const std::unique_ptr<SocketImpl>& m_socket;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKETIMPL_HPP
