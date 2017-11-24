#ifndef BULL_NETWORK_SOCKET_SOCKET_HPP
#define BULL_NETWORK_SOCKET_SOCKET_HPP

#include <Bull/Core/Pattern/ImplPtr.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketHandler.hpp>
#include <Bull/Network/Socket/SocketType.hpp>

namespace Bull
{
    class SocketPoller;

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

        /*! \brief Get the length of data in pending to be read
         *
         * \return The length
         *
         */
        std::size_t getPendingLength() const;

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

        /*! \brief Create the Socket
         *
         * \param handler The SocketHandler
         *
         * \return True if the Socket was created successfully
         *
         */
        bool create(SocketHandler handler);

        /*! \brief Close the Socket
         *
         */
        void close();

    protected:

        friend class SocketPoller;

        /*! \brief Constructor by movement
         *
         * \param move The Socket to move
         *
         */
        Socket(Socket&& move) noexcept = default;

        /*! \brief Basic assignment operator by movement
         *
         * \param move The Socket to move
         *
         * \return This
         *
         */
        Socket& operator=(Socket&& move) noexcept = default;

        /*! \brief Get the SocketImpl of the Socket
         *
         * \return The SocketImpl
         *
         */
        const ImplPtr<prv::SocketImpl>& getImpl() const;

    private:

        ImplPtr<prv::SocketImpl> m_impl;
        SocketType               m_type;
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKET_HPP
