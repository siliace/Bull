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

        /*! @brief Destructor
         *
         */
        virtual ~Socket();

        /*! @brief Close the socket
         *
         */
        void close();

        /*! @brief Enable or disable the blocking mode
         *
         * @param enable True to enable
         *
         */
        void enableBlockingMode(bool enable = true);

        /*! @brief Check whether the blocking mode is enable
         *
         * @return True if enable
         *
         */
        bool isEnableBlockingMode() const;

        /*! @brief Get the type of the Socket
         *
         * @return Return the type
         *
         */
        Type getType() const;

        /*! @brief Get the state of the Socket
         *
         * @return The state
         *
         */
        State getState() const;

        /*! @brief Get the protocol of the Socket
         *
         * @return The protocol
         *
         */
        NetProtocol getProtocol() const;

    protected:

        /*! @brief Constructor
         *
         * @param type The type of Socket to create
         *
         */
        Socket(Type type);

        /*! @brief Create the socket handler according to a NetProtocol
         *
         * @param protocol The used by the Socket to communicate
         *
         * @return Return true if the handler was created successfully, false otherwise
         *
         */
        bool create(NetProtocol protocol);

        /*! @brief Create the socket handler from another one
         *
         * @param handler The new handler
         *
         */
        void create(SocketHandler handler);

    protected:

        State         m_state;
        SocketHandler m_handler;

    private:

        Type        m_type;
        bool        m_blocking;
        NetProtocol m_protocol;
    };
}

#endif // BULL_SOCKET_HPP
