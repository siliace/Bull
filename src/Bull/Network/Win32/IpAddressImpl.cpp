#include <winsock2.h>
#include <ws2tcpip.h>

#include <Bull/Network/Win32/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        struct WsaInitializer
        {
            WsaInitializer()
            {
                WSADATA wsa;
                WSAStartup(MAKEWORD(2, 2), &wsa);
            }

            ~WsaInitializer()
            {
                WSACleanup();
            }
        };

        WsaInitializer init;

        IpAddress IpAddressImpl::resolveIpv4(const String& hostname)
        {
            Uint32 ip = inet_addr(hostname);

            if(ip != INADDR_NONE)
            {
                return IpAddress(ip);
            }

            addrinfo hints;
            addrinfo* result = nullptr;
            ZeroMemory(&hints, sizeof(addrinfo));
            hints.ai_family   = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;

            int error = getaddrinfo(hostname, "http", &hints, &result);

            if(error == 0)
            {
                if(result)
                {
                    ip = reinterpret_cast<sockaddr_in*>(result->ai_addr)->sin_addr.s_addr;
                    freeaddrinfo(result);

                    return IpAddress(ip);
                }
            }

            return IpAddress::None;
        }

        IpAddress IpAddressImpl::resolveIpv6(const String& hostname)
        {
            return IpAddress::None;
        }
    }
}
