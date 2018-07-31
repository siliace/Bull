#include <iphlpapi.h>
#include <icmpapi.h>

#include <Bull/Network/Icmp/Win32/IcmpImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Duration IcmpImpl::ping(const IpAddressV4& address, const Duration& timeout)
        {
            Duration duration = Duration::Infinite;
            HANDLE icmpHandle = IcmpCreateFile();

            if(icmpHandle != INVALID_HANDLE_VALUE)
            {
                std::vector<Uint8> request(32);
                IPAddr addr = address.toInt();
                std::vector<Uint8> response(sizeof(ICMP_ECHO_REPLY) + request.size());

                if(IcmpSendEcho(icmpHandle,
                                addr,
                                &request[0], request.size(),
                                nullptr,
                                &response[0], response.size(),
                                timeout.asMilliseconds()) > 0)
                {
                    const ICMP_ECHO_REPLY* reply = reinterpret_cast<const ICMP_ECHO_REPLY*>(response.data());

                    duration = Duration::milliseconds(reply->RoundTripTime);
                }

                IcmpCloseHandle(icmpHandle);
            }

            return duration;
        }
    }
}