#ifndef BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP
#define BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Network/Socket/SocketHeader.hpp>

namespace Bull
{
    class WsaService : public Singleton<WsaService>
    {
    public:

        /*! \brief Default constructor
         *
         */
        WsaService();

        /*! \brief Destructor
         *
         */
        ~WsaService();

        /*! \brief Get the vendor of the WsaService
         *
         * \return The vendor
         *
         */
        String getVendor() const;

        /*! \brief Get the last error
         *
         * \return The last error
         *
         */
        int getLastError() const;

    private:

        WSAData m_data;
    };
}

#endif // BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP
