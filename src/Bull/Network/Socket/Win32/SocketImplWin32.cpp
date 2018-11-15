#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/Win32/SocketImplWin32.hpp>
#include <Bull/Network/Socket/Win32/WsaService.hpp>

namespace Bull
{
    namespace prv
    {
        namespace
        {
            WsaService& wsa = WsaService::getInstance();
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
                Throw(InternalError, "Failed to switch blocking mode");
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
                Throw(InternalError, "Failed to get pending length");
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