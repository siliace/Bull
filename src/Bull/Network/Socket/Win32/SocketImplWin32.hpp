#ifndef BULL_NETWORK_SOCKET_WIN32_SOCKETIMPLWIN32_HPP
#define BULL_NETWORK_SOCKET_WIN32_SOCKETIMPLWIN32_HPP

#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SocketImplWin32 : public SocketImpl
        {
        public:

            static constexpr SocketHandler InvalidHandler = INVALID_SOCKET;

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
            SocketImplWin32();

            /*! \brief Destructor
             *
             */
            virtual ~SocketImplWin32();

            /*! \brief Enable the blocking mode of the SocketImplWin32
             *
             * \param enable True to enable
             *
             */
            void enableBlockingMode(bool enable) override;

            /*! \brief Tell whether SocketImplWin32 is in blocking mode
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

#endif // BULL_NETWORK_SOCKET_WIN32_SOCKETIMPLWIN32_HPP
