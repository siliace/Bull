#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Network/Socket/Win32/SocketPollerImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        bool SocketPollerImplWin32::wait()
        {
            if(!m_sockets.empty())
            {
                int result = WSAPoll(&m_sockets[0], static_cast<ULONG>(m_sockets.size()), -1);

                if(result == SOCKET_ERROR)
                {
                    throw RuntimeError("Failed to poll sockets");
                }

                return result > 0;
            }

            return false;
        }

        bool SocketPollerImplWin32::wait(const Time& timeout)
        {
            if(!m_sockets.empty())
            {
                int result = WSAPoll(&m_sockets[0], static_cast<ULONG>(m_sockets.size()), static_cast<int>(timeout.asMilliseconds()));

                if(result == SOCKET_ERROR)
                {
                    throw RuntimeError("Failed to poll sockets");
                }

                return result > 0;
            }

            return false;
        }
    }
}