#ifndef BULL_NETWORK_SOCKET_SOCKETSTATE_HPP
#define BULL_NETWORK_SOCKET_SOCKETSTATE_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Network/Export.hpp>
#include <Bull/Network/Socket/SocketError.hpp>

namespace Bull
{
    struct BULL_NETWORK_API SocketState
    {
        /*! \brief Constructor
         *
         * \param error The SocketError
         *
         */
        explicit SocketState(SocketError error = SocketError_Ok);

        /*! \brief Tell whether the Socket is in error
         *
         * \return True if the Socket is in error
         *
         */
        bool isError() const;

        /*! \brief Convert the SocketState to a bool
         *
         * \return True if the Socket is not in error
         *
         */
        operator bool() const;

        SocketError error;
    };
}

#endif // BULL_NETWORK_SOCKET_SOCKETSTATE_HPP
