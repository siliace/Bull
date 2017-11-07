#include <Bull/Network/Socket/SocketState.hpp>

namespace Bull
{
    SocketState::SocketState(SocketError error) :
        error(error)
    {
        /// Nothing
    }

    bool SocketState::isError() const
    {
        return error != SocketError_Ok;
    }

    SocketState::operator bool() const
    {
        return !isError();
    }
}