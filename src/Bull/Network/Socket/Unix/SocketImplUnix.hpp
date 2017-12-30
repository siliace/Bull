#ifndef BULL_NETWORK_SOCKET_UNIX_SOCKETIMPLUNIX_HPP
#define BULL_NETWORK_SOCKET_UNIX_SOCKETIMPLUNIX_HPP

#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketImplUnix : public SocketImpl
        {
        public:

            static constexpr SocketHandler InvalidHandler = -1;

            /*! \brief Get the last socket error
             *
             * \return The error
             *
             */
            static SocketError getLastError();

        public:

            /*! \brief Default constructor
             *
             */
            SocketImplUnix();

            /*! \brief Destructor
             *
             */
            virtual ~SocketImplUnix();

            /*! \brief Enable the blocking mode of the SocketImplUnix
             *
             * \param enable True to enable
             *
             */
            void enableBlockingMode(bool enable) override;

            /*! \brief Tell whether SocketImplUnix is in blocking mode
             *
             * \return True if the blocking mode is enable
             *
             */
            bool isEnableBlockingMode() const override;

            /*! \brief Get the length of data in pending to be read
             *
             * \return The length
             *
             */
            std::size_t getPendingLength() const override;

        private:

            bool m_blocking;
        };
    }
}

#endif // BULL_NETWORK_SOCKET_UNIX_SOCKETIMPLUNIX_HPP
