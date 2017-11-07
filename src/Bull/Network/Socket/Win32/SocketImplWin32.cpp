#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/Win32/SocketImplWin32.hpp>
#include <Bull/Network/Socket/Win32/WsaService.hpp>

namespace Bull
{
    namespace prv
    {
        namespace
        {
            WsaService::Instance wsa = WsaService::get();
        }

        SocketError SocketImplWin32::getLastError()
        {
            DWORD error = wsa->getLastError();

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

            u_long yes = 1, no = 0;

            ioctlsocket(getHandler(), FIONBIO, m_blocking ? &yes : &no);
        }

        bool SocketImplWin32::isEnableBlockingMode() const
        {
            return m_blocking;
        }

        std::size_t SocketImplWin32::getPendingLength() const
        {
            u_long length = 0;

            ioctlsocket(getHandler(), FIONREAD, &length);

            return length;
        }

        SocketImplWin32::SocketImplWin32() :
            m_blocking(true)
        {
            /// Nothing
        }
    }
}