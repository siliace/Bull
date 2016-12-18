#include <Bull/Network/Win32/Wsa.hpp>

namespace Bull
{
    namespace prv
    {
        namespace
        {
            struct WsaInitializer
            {
                WsaInitializer()
                {
                    WSAData m_data;
                    WSAStartup(MAKEWORD(2, 2), &m_data);
                }

                ~WsaInitializer()
                {
                    WSACleanup();
                }
            };

            WsaInitializer init;
        }

        /*! \brief Get the last WSA error
         *
         * \return Return the error
         *
         */
        Wsa::Error getLastError()
        {
            switch(WSAGetLastError())
            {
                case 0:                  return Wsa::Error::Ok;
                case WSASYSNOTREADY:     return Wsa::Error::SystemNotReady;
                case WSAVERNOTSUPPORTED: return Wsa::Error::VersionNotSupported;
                case WSAEINPROGRESS:     return Wsa::Error::InProgress;
                case WSAEFAULT:          return Wsa::Error::EFault;
            }

            return Wsa::Error::Unknown;
        }
    }
}
