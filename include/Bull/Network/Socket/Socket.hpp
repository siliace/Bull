#ifndef BULL_NETWORK_SOCKET_SOCKET_HPP
#define BULL_NETWORK_SOCKET_SOCKET_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Address/IpAddress.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketType.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketImpl;
    }

    class BULL_NETWORK_API Socket : public NonCopyable
    {

    public:

        /*! \brief Destructor
         *
         */
        virtual ~Socket();

        /*! \brief Enable the blocking mode of the Socket
         *
         * \param enable True to enable
         *
         */
        void enableBlockingMode(bool enable);

        /*! \brief Tell whether Socket is in blocking mode
         *
         * \return True if the blocking mode is enable
         *
         */
        bool isEnableBlockingMode() const;

        /*! \brief Get the SocketType of the Socket
         *
         * \return The SocketType
         *
         */
        SocketType getType() const;

    protected:

        /*! \brief Constructor
         *
         * \param type The type of the Socket
         *
         */
        explicit Socket(SocketType type);

        /*! \brief Create the Socket
         *
         * \param protocol The NetProtocol to use in the Socket
         *
         * \return True if the Socket was created successfully
         *
         */
        bool create(NetProtocol protocol);

        /*! \brief Close the Socket
         *
         */
        void close();

        /*! \brief Get the SocketImpl of the Socket
         *
         * \return The SocketImpl
         *
         */
        const std::unique_ptr<prv::SocketImpl>& getImpl() const;

    private:

        std::unique_ptr<prv::SocketImpl> m_impl;
        SocketType                       m_type;
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKET_HPP
