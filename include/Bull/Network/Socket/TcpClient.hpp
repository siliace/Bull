#ifndef BULL_NETWORK_SOCKET_TCPCLIENT_HPP
#define BULL_NETWORK_SOCKET_TCPCLIENT_HPP

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Time/Time.hpp>

#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketHandler.hpp>
#include <Bull/Network/Socket/SocketState.hpp>

namespace Bull
{
    class TcpServer;

    namespace prv
    {
        class TcpClientImpl;
    }

    class BULL_NETWORK_API TcpClient : public Socket
    {
    public:

        /*! \brief Default constructor
         *
         */
        TcpClient();

        /*! \brief Constructor by movement
         *
         * \param move The TcpClient to move
         *
         */
        TcpClient(TcpClient&& move) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~TcpClient();

        /*! \brief Basic assignment operator by movement
         *
         * \param move The TcpClient to move
         *
         * \return This
         *
         */
        TcpClient& operator=(TcpClient&& move) noexcept = default;

        /*! \brief Connect the TcpClient to a remote host
         *
         * \param address The IpAddress of the remote host
         * \param port    The NetPort of the remote host
         *
         * \return The new SocketState
         *
         */
        SocketState connect(const IpAddressWrapper& address, NetPort port);

        /*! \brief Connect the TcpClient to a remote host
         *
         * \param address The IpAddress of the remote host
         * \param port    The NetPort of the remote host
         * \param timeout The time before the function fail
         * \param pause   The time between two try
         *
         * \return The new SocketState
         *
         */
        SocketState connect(const IpAddressWrapper& address, NetPort port, const Time& timeout, const Time& pause = Time::milliseconds(20.f));

        /*! \brief Tell whether the TcpClient is connected
         *
         * \return True if the TcpClient is connected
         *
         */
        bool isConnected() const;

        /*! \brief Disconnect the TcpClient from the remote host
         *
         */
        void disconnect();

        /*! \brief Send a data buffer the remote host
         *
         * \param data   Data to send
         * \param length The length of data to send
         * \param sent   The amount of bytes sent
         *
         * \return The new SocketState
         *
         */
        SocketState send(const void* data, std::size_t length, std::size_t& sent);

        /*! \brief Receive data from the remote host
         *
         * \param data     Data to receive
         * \param length   The length of data to receive
         * \param received The amount of bytes received
         *
         * \return The new SocketState
         *
         */
        SocketState receive(void* data, std::size_t length, std::size_t& received);

        /*! \brief Get the remote NetPort
         *
         * \return The NetPort
         *
         */
        NetPort getRemotePort() const;

        /*! \brief Get the remote IpAddress
         *
         * \return The IpAddress
         *
         */
        const IpAddress& getRemoteAddress() const;

    private:

        friend class TcpServer;

        /*! \brief Create the TcpClient
         *
         * \param handler The new SocketHandler
         * \param address The new IpAddress
         * \param port    The new NetPort
         *
         * \return True if the TcpClient was created successfully
         *
         */
        bool create(SocketHandler handler, const IpAddressWrapper& address, NetPort port);

    private:

        ImplPtr<prv::TcpClientImpl> m_impl;
        NetPort                     m_hostPort;
        IpAddressWrapper            m_hostAddress;
    };
}

#endif // BULL_NETWORK_SOCKET_TCPCLIENT_HPP
