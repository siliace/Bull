#ifndef BULL_TCPLISTENNER_HPP
#define BULL_TCPLISTENNER_HPP

#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/Socket.hpp>

namespace Bull
{
    class TcpSocket;

    class BULL_API TcpListenner : public Socket
    {
    public:

        static constexpr std::size_t DefaultQueueLength = 10;

    public:

        /*! \brief Default constructor
         *
         */
        TcpListenner();

        /*! \brief Listen a port
         *
         * \param protocol The protocol to listen
         * \param port     The port to listen
         * \param error    A pointer to store the error
         *
         * \return The new state of the TcpListenner
         *
         */
        State listen(NetProtocol protocol, Uint16 port, Socket::Error* error = nullptr);

        /*! \brief Listen a port
         *
         * \param address The IpAddress to listen
         * \param port    The port to listen
         * \param error   A pointer to store the error
         *
         * \return The new state of the TcpListenner
         *
         */
        State listen(const IpAddress& address, Uint16 port, Socket::Error* error = nullptr);

        /*! \brief Listen a port
         *
         * \param protocol    The protocol to listen
         * \param port        The port to listen
         * \param queueLength The maximum of connection accepted
         * \param error       A pointer to store the error
         *
         * \return The new state of the TcpListenner
         *
         */
        State listen(NetProtocol protocol, Uint16 port, std::size_t queueLength, Socket::Error* error = nullptr);

        /*! \brief Listen a port
         *
         * \param address The IpAddress to listen
         * \param port    The port to listen
         * \param queueLength The maximum of connection accepted
         * \param error   A pointer to store the error
         *
         * \return The new state of the TcpListenner
         *
         */
        State listen(const IpAddress& address, Uint16 port, std::size_t queueLength, Socket::Error* error = nullptr);

        /*! \brief Accept an incoming TCP connection
         *
         * \param client The client socket
         * \param error  A pointer to store the error
         *
         * \return True if the client has been accepted
         *
         */
        bool accept(TcpSocket* client, Socket::Error* error = nullptr);

        /*! \brief Check whether the TcpListenner is listening
         *
         * \return True if listening
         *
         */
        bool isListening();

    private:

        Uint16    m_boundPort;
        IpAddress m_boundAddress;
    };
}

#endif // BULL_TCPLISTENNER_HPP
