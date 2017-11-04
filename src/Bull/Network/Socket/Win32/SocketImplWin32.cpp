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

        SocketImplWin32::~SocketImplWin32()
        {
            if(getHandler() != InvalidHandler)
            {
                closesocket(getHandler());
            }
        }

        void SocketImplWin32::enableBlockingMode(bool enable)
        {
            if(getHandler() != InvalidHandler)
            {
                m_blocking = enable;

                u_long yes = 1, no = 0;

                ioctlsocket(getHandler(), FIONBIO, m_blocking ? &yes : &no);
            }
        }

        bool SocketImplWin32::isEnableBlockingMode() const
        {
            return m_blocking;
        }

        SocketImplWin32::SocketImplWin32() :
            m_blocking(true)
        {
            /// Nothing
        }
    }
}