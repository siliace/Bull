#ifndef BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP
#define BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP

#include <string>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Network/Socket/SocketHeader.hpp>

namespace Bull
{
    class WsaService : public Singleton<WsaService>
    {
    public:

        /** \brief Destructor
         *
         */
        ~WsaService();

        /** \brief Get the vendor of the WsaService
         *
         * \return The vendor
         *
         */
        std::string getVendor() const;

        /** \brief Get the last error
         *
         * \return The last error
         *
         */
        int getLastError() const;

    private:

        friend class Singleton<WsaService>;

        /** \brief Default constructor
         *
         */
        WsaService();

    private:

        WSAData m_data;
    };
}

#endif // BULL_NETWORK_SOCKET_WIN32_WSASERVICE_HPP
