#ifndef BULL_NETWORK_SOCKET_HPP
#define BULL_NETWORK_SOCKET_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Export.hpp>
#include <Bull/Network/IpAddress.hpp>
#include <Bull/Network/SocketHandler.hpp>

namespace Bull
{
    class BULL_NETWORK_API Socket : public NonCopyable
    {
    public:

        enum Type
        {
            Tcp,
            Udp,
            Raw
        };

        enum State
        {
            Ready,
            NotReady,
            Partial,
            Disconnected,
            ConnectionRefused,
            Error,
        };

        typedef unsigned short Port;

        static constexpr Port AnyPort = 0;

    public:

        /*! \brief Destructor
         *
         */
        virtual ~Socket();

        /*! \brief Close the Socket
         *
         */
        void close();

        /*! \brief Enable blocking state
         *
         * \param blocking True to enable blocking state
         *
         * \return This
         *
         */
        Socket& enableBlocking(bool blocking = true);

        /*! \brief Check whether the Socket is in blocking mode
         *
         * \return True if is in blocking mode
         *
         */
        bool isEnableBlocking() const;

    protected:

        /*! \brief Constructor
         *
         * \param type The type of the Socket
         */
        Socket(Type type);

        /*! \brief Create the Socket
         *
         * \param protocol The protocol to use in the Socket
         *
         */
        void create(IpAddress::NetProtocol protocol);

        /*! \brief Reset the SocketHandler
         *
         * \param handler The handler to use
         *
         */
        void reset(SocketHandler handler);

        /*! \brief Get the SocketHandler
         *
         * \return The SocketHandler
         *
         */
        SocketHandler getHandler() const;

    private:

        Type                   m_type;
        SocketHandler          m_handler;
        IpAddress::NetProtocol m_protocol;
        bool                   m_isBlocking;
    };
}

#endif // BULL_NETWORK_SOCKET_HPP
