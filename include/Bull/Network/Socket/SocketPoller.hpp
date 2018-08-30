#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLER_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLER_HPP

#include <Bull/Core/Time/Duration.hpp>

#include <Bull/Network/Socket/Socket.hpp>
#include <Bull/Network/Socket/SocketPollerEvent.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketPollerImpl;
    }

    class BULL_NETWORK_API SocketPoller : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        SocketPoller();

        /*! \brief Constructor by movement
         *
         * \param move The SocketPoller to move
         *
         */
        SocketPoller(SocketPoller&& move) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~SocketPoller();

        /*! \brief Basic assignment operator by movement
         *
         * \param move The SocketPoller to move
         *
         * \return This
         *
         */
        SocketPoller& operator=(SocketPoller&& move) noexcept = default;

        /*! \brief Add a Socket to the SocketPoller
         *
         * \param socket The Socket to add
         * \param events Events to listen
         *
         */
        void add(const Socket& socket, SocketPollerEvent event);

        /*! \brief Remove a Socket from SocketPoller
         *
         * \param socket The Socket to remove
         *
         */
        void remove(const Socket& socket);

        /*! \brief Clear the SocketPoller
         *
         */
        void clear();

        /*! \brief Wait until a Socket is ready to read or write
         *
         * \return True if at less one socket can be read or written
         *
         */
        bool wait();

        /*! \brief Wait until a Socket is ready to read or write
         *
         * \param timeout The time before the function fail
         *
         * \return True if at less one socket can be read or written
         *
         */
        bool wait(const Duration& timeout);

        /*! \brief Tell whether a Socket can be waited by the SocketPoller
         *
         * \param socket The Socket
         *
         * \return True if the Socket can be waited
         *
         */
        bool isAdded(const Socket& socket);

        /*! \brief Tell whether a Socket is ready to read
         *
         * \param socket The Socket to check the state
         *
         * \return True if the Socket is ready to read
         *
         */
        bool isReadyToRead(const Socket& socket);

        /*! \brief Tell whether a Socket is ready to write
         *
         * \param socket The Socket to check the state
         *
         * \return True if the Socket is ready to write
         *
         */
        bool isReadyToWrite(const Socket& socket);

    private:

        std::unique_ptr<prv::SocketPollerImpl> m_impl;
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLER_HPP
