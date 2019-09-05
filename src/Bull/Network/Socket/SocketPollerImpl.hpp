#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP

#include <memory>
#include <vector>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/Duration.hpp>

#include <Bull/Network/Socket/SocketHandler.hpp>
#include <Bull/Network/Socket/SocketPollDescriptor.hpp>
#include <Bull/Network/Socket/SocketPollerEvent.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketPollerImpl : public NonCopyable
        {
        public:

            /** \brief Create an OS specific instance of SocketPollerImpl
             *
             * \return The created instance
             *
             */
            static std::unique_ptr<SocketPollerImpl> createInstance();

        private:

            using SocketPollDescriptorList = std::vector<SocketPollDescriptor>;

        public:

            /** \brief Add a Socket to the SocketPollerImpl
             *
             * \param socket The Socket to add
             * \param events Events to listen
             *
             */
            void add(SocketHandler socket, SocketPollerEvent event);

            /** \brief Remove a Socket from SocketPollerImpl
             *
             * \param socket The Socket to remove
             *
             */
            void remove(SocketHandler socket);

            /** \brief Clear the SocketPollerImpl
             *
             */
            void clear();

            /** \brief Wait until a Socket is ready to read or write
             *
             * \return True if the SocketPollerImpl waited successfully
             *
             */
            bool wait();

            /** \brief Wait until a Socket is ready to read or write
             *
             * \param timeout The time before the function fail
             *
             * \return True if the SocketPollerImpl waited successfully
             *
             */
            bool wait(const Duration& timeout);

            /** \brief Tell whether a Socket can be waited by the SocketPollerImpl
             *
             * \param socket The Socket
             *
             * \return True if the Socket can be waited
             *
             */
            bool isAdded(SocketHandler socket);

            /** \brief Tell whether a Socket is ready to read
             *
             * \param socket The Socket to check the state
             *
             * \return True if the Socket is ready to read
             *
             */
            bool isReadyToRead(SocketHandler socket);

            /** \brief Tell whether a Socket is ready to write
             *
             * \param socket The Socket to check the state
             *
             * \return True if the Socket is ready to write
             *
             */
            bool isReadyToWrite(SocketHandler socket);

        protected:

            /** \brief Default constructor
             *
             */
            SocketPollerImpl() = default;

            /** \brief Poll sockets
             *
             * \param sockets Sockets to poll
             * \param timeout The time before the function fail
             *
             * \return The number of sockets updated during the poll
             *
             */
            virtual int poll(SocketPollDescriptorList& sockets, int timeout) const = 0;

        private:

            /** \brief Get an iterator to a SocketHandler
             *
             * \param socket The SocketHandler to get
             *
             * \return The iterator
             *
             */
            SocketPollDescriptorList::iterator getSocketPoll(SocketHandler socket);

            SocketPollDescriptorList m_sockets;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP
