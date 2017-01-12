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
        int Wsa::getLastError()
        {
            return WSAGetLastError();
        }
    }
}
