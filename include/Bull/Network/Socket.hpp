#ifndef BULL_SOCKET_HPP
#define BULL_SOCKET_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Network/NetProtocol.hpp>
#include <Bull/Network/SocketHandler.hpp>

namespace Bull
{
    class BULL_API Socket : public NonCopyable
    {
    public:

        enum Type
        {
            Tcp,
            Udp,
            Raw,
        };

        enum Error
        {
            Ok,
        };

        enum State
        {
            Bound,
            Connecting,
            Connected,
            NotConnected,
            Resolving,
        };

    public:

        /*! \brief Destructor
         *
         */
        virtual ~Socket();

        /*! \brief Close the socket
         *
         */
        void close();

        /*! \brief Get the type of the Socket
         *
         * \return Return the type
         *
         */
        Type getType() const;

        /*! \brief Get the state of the socket
         *
         * \return Return the state
         *
         */
        State getState() const;

        /*! \brief
         *
         * \return
         *
         */
        NetProtocol getProtocol() const;

    protected:

        /*! \brief Constructor
         *
         * \param type The type of Socket to create
         *
         */
        Socket(Type type);

        /*! \brief Create the socket handler according to a NetProtocol
         *
         * \param protocol The used by the Socket to communicate
         *
         * \return Return true if the handler was created successfully, false otherwise
         *
         */
        bool create(NetProtocol protocol);

        /*! \brief Create the socket handler from another one
         *
         * \param handler The new handler
         *
         */
        void create(SocketHandler handler);

    protected:

        State         m_state;
        SocketHandler m_handler;

    private:

        Type        m_type;
        NetProtocol m_protocol;
    };
}

#endif // BULL_SOCKET_HPP
