#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>

#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/Win32/SocketImplWin32.hpp>
#include <Bull/Network/Socket/Win32/WsaService.hpp>

namespace Bull
{
    namespace prv
    {
        namespace
        {
            WsaService::Instance wsa = WsaService::getInstance();
        }

        SocketError SocketImplWin32::getLastError()
        {
            int error = wsa->getLastError();

            if(error)
            {
                switch(error)
                {
                    case WSAEFAULT:       return SocketError_Error;
                    case WSAENOBUFS:      return SocketError_Error;
                    case WSAENETDOWN:     return SocketError_Error;
                    case WSAEWOULDBLOCK:  return SocketError_Error;
                    case WSAETIMEDOUT:    return SocketError_Timeout;
                    case WSAECONNABORTED: return SocketError_Disconnected;
                    case WSAENETUNREACH:  return SocketError_NetworkFailed;
                    case WSAEHOSTUNREACH: return SocketError_NetworkFailed;
                    case WSAECONNREFUSED: return SocketError_ConnectionRefused;
                }
            }

            return SocketError_Ok;
        }

        SocketImplWin32::~SocketImplWin32()
        {
            closesocket(getHandler());
        }

        void SocketImplWin32::enableBlockingMode(bool enable)
        {
            m_blocking = enable;

            u_long blocking = m_blocking ? 1 : 0;

            if(ioctlsocket(getHandler(), FIONBIO, &blocking) != NO_ERROR)
            {
                Throw(InternalError, "SocketImplWin32::enableBlockingMode", "Failed to switch blocking mode");
            }
        }

        bool SocketImplWin32::isEnableBlockingMode() const
        {
            return m_blocking;
        }

        std::size_t SocketImplWin32::getPendingLength() const
        {
            u_long length = 0;

            if(ioctlsocket(getHandler(), FIONREAD, &length) != NO_ERROR)
            {
                Throw(InternalError, "SocketImplWin32::getPendingLength", "Failed to get pending length");
            }

            return length;
        }

        SocketImplWin32::SocketImplWin32() :
            m_blocking(true)
        {
            /// Nothing
        }
    }
}