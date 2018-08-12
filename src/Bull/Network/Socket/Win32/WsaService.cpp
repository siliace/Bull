#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Network/Socket/Win32/WsaService.hpp>

namespace Bull
{
    WsaService::WsaService()
    {
        if(WSAStartup(MAKEWORD(2, 2), &m_data) != 0)
        {
            Throw(InternalError, "WsaService::WsaService", "Failed to initialize Wsa Service");
        }
    }

    WsaService::~WsaService()
    {
        WSACleanup();
    }

    String WsaService::getVendor() const
    {
        return m_data.lpVendorInfo;
    }

    int WsaService::getLastError() const
    {
        return WSAGetLastError();
    }
}