#ifndef BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP
#define BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP

#include <vector>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/Time.hpp>

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

            /*! \brief Create an OS specific instance of SocketPollerImpl
             *
             * \return The created instance
             *
             */
            static SocketPollerImpl* createInstance();

        private:

            using SocketPollDescriptorList = std::vector<SocketPollDescriptor>;

        public:

            /*! \brief Add a Socket to the SocketPollerImpl
             *
             * \param socket The Socket to add
             * \param events Events to listen
             *
             */
            void add(SocketHandler socket, SocketPollerEvent event = SocketPollerEvent_All);

            /*! \brief Remove a Socket from SocketPollerImpl
             *
             * \param socket The Socket to remove
             *
             */
            void remove(SocketHandler socket);

            /*! \brief Clear the SocketPollerImpl
             *
             */
            void clear();

            /*! \brief Wait until a Socket is ready to read or write
             *
             * \return True if the SocketPollerImpl waited successfully
             *
             */
            virtual bool wait() = 0;

            /*! \brief Wait until a Socket is ready to read or write
             *
             * \param timeout The time before the function fail
             *
             * \return True if the SocketPollerImpl waited successfully
             *
             */
            virtual bool wait(const Time& timeout) = 0;

            /*! \brief Tell whether a Socket can be waited by the SocketPollerImpl
             *
             * \param socket The Socket
             *
             * \return True if the Socket can be waited
             *
             */
            bool isAdded(SocketHandler socket);

            /*! \brief Tell whether a Socket is ready to read
             *
             * \param socket The Socket to check the state
             *
             * \return True if the Socket is ready to read
             *
             */
            bool isReadyToRead(SocketHandler socket);

            /*! \brief Tell whether a Socket is ready to write
             *
             * \param socket The Socket to check the state
             *
             * \return True if the Socket is ready to write
             *
             */
            bool isReadyToWrite(SocketHandler socket);

        protected:

            /*! \brief Default constructor
             *
             */
            SocketPollerImpl() = default;

            SocketPollDescriptorList m_sockets;

        private:

            /*! \brief Get an iterator to a SocketHandler
             *
             * \param socket The SocketHandler to get
             *
             * \return The iterator
             *
             */
            SocketPollDescriptorList::iterator getSocketPoll(SocketHandler socket);
        };
    }
}

#endif // BULL_NETWORK_SOCKET_SOCKETPOLLERIMPL_HPP
