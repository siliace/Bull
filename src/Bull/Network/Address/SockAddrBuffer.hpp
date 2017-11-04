#ifndef BULL_NETWORK_ADDRESS_SOCKADDRBUFFER_HPP
#define BULL_NETWORK_ADDRESS_SOCKADDRBUFFER_HPP

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketHeader.hpp>

namespace Bull
{
    namespace prv
    {
        class SockAddrBuffer
        {
        public:

            /*! \brief Constructor
             *
             * \param addr   The sockaddr to convert
             * \param length The length of the sockaddr
             *
             */
            SockAddrBuffer(const sockaddr& address, int length);

            /*! \brief Constructor
             *
             * \param wrapper The IpAddress to convert
             * \param port    The NetPort to convert
             *
             */
            SockAddrBuffer(const IpAddressWrapper& wrapper, NetPort port);

            /*! \brief Get the NetPort of the SockAddrBuffer
             *
             * \return The NetPort
             *
             */
            NetPort getPort() const;

            /*! \brief Get the IpAddress of the SockAddrBuffer
             *
             * \param return The IpAddress
             *
             */
            IpAddressWrapper getIpAddress();

            /*! \brief Get the length of the SockAddrBuffer
             *
             * \return The length
             *
             */
            int getLength() const;

            /*! \brief Convert the SockAddrBuffer to a sockaddr
             *
             * \return The sockaddr
             *
             */
            const sockaddr* getSockAddr() const;

        private:

            /*! \brief Create a SockAddrBuffer with bytes from an IpAddressV4
             *
             * \param address The IpAddressV4
             * \param port    The NetPort
             *
             */
            void createFromIpAddressV4(const IpAddress& address, NetPort port);

            /*! \brief Create a SockAddrBuffer with bytes from an IpAddressV6
             *
             * \param address The IpAddressV6
             * \param port    The NetPort
             *
             */
            void createFromIpAddressV6(const IpAddress& address, NetPort port);

            /*! \brief Create an IpAddressV4 from a SockAddrBuffer
             *
             * \param return The IpAddress
             *
             */
            IpAddressV4 createFromSockAddrV4() const;

            /*! \brief Create an IpAddressV6 from a SockAddrBuffer
             *
             * \param return The IpAddress
             *
             */
            IpAddressV6 createFromSockAddrV6() const;

            sockaddr m_addr;
            int      m_length;
        };
    }
}

#endif // BULL_NETWORK_ADDRESS_SOCKADDRBUFFER_HPP