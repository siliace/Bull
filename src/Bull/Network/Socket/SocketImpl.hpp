#ifndef BULL_NETWORK_SOCKET_SOCKETIMPL_HPP
#define BULL_NETWORK_SOCKET_SOCKETIMPL_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Network/Address/IpAddressWrapper.hpp>
#include <Bull/Network/Address/NetPort.hpp>
#include <Bull/Network/Socket/SocketHandler.hpp>
#include <Bull/Network/Socket/SocketType.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketImpl : public NonCopyable
        {
        public:

            /*! \brief Create an OS specific instance of SocketImpl
             *
             */
            static SocketImpl* createInstance();

            /*! \brief Get an invalid SocketHandler value
             *
             * \return The SocketHandler
             *
             */
            static SocketHandler getInvalidSocket();

        private:

            /*! \brief Convert a SocketType to a SOCK value
             *
             * \param type The SocketType
             *
             * \return The SOCK value
             *
             */
            int convertSocketType(SocketType type);

            /*! \brief Convert a NetProtocol to the equivalent address family value
             *
             * \param protocol The NetProtocol
             *
             * \return The address family value
             */
            int convertNetProtocol(NetProtocol protocol);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~SocketImpl();

            /*! \brief Create the SocketImpl
             *
             * \param protocol The NetProtocol to use on the SocketImpl
             * \param type     The SocketType to use on the SocketType
             *
             * \return True if the SocketImpl was created successfully
             *
             */
            bool create(NetProtocol protocol, SocketType type);

            /*! \brief Create the SocketImpl
             *
             * \param handler The SocketHandler
             *
             * \return True if the SocketImpl was created successfully
             *
             */
            bool create(SocketHandler handler);

            /*! \brief Tell whether the SocketImpl is valid
             *
             * \return True if the SocketImpl is valid
             *
             */
            bool isValid() const;

            /*! \brief Enable the blocking mode of the SocketImpl
             *
             * \param enable True to enable
             *
             */
            virtual void enableBlockingMode(bool enable) = 0;

            /*! \brief Tell whether SocketImpl is in blocking mode
             *
             * \return True if the blocking mode is enable
             *
             */
            virtual bool isEnableBlockingMode() const = 0;

            /*! \brief Get the length of data in pending to be read
             *
             * \return The length
             *
             */
            virtual std::size_t getPendingLength() const = 0;

            /*! \brief Get the SocketHandler of the SocketImpl
             *
             * \return The SocketHandler
             *
             */
            SocketHandler getHandler() const;

        protected:

            /*! \brief Default constructor
             *
             */
            SocketImpl();

        private:

            SocketHandler m_handler;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_SOCKETIMPL_HPP
