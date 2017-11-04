#ifndef BULL_NETWORK_SOCKET_UDPSOCKET_HPP
#define BULL_NETWORK_SOCKET_UDPSOCKET_HPP

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/Socket.hpp>

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

        /*! \brief Destructor
         *
         */
        ~UdpSocket();

        /*! \brief
         *
         * \param address
         * \param port
         *
         * \return
         *
         */
        bool bind(NetPort port, const IpAddressWrapper& address = IpAddressV4::Any);

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

        std::unique_ptr<prv::UdpSocketImpl> m_impl;
    };
}

#endif // BULL_NETWORK_SOCKET_UDPSOCKET_HPP
