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
                ByteArray request(32);
                IPAddr addr = address.toInt();
                ByteArray response(sizeof(ICMP_ECHO_REPLY) + request.getCapacity());

                if(IcmpSendEcho(icmpHandle,
                                addr,
                                &request[0], request.getCapacity(),
                                nullptr,
                                &response[0], response.getCapacity(),
                                timeout.asMilliseconds()) > 0)
                {
                    const ICMP_ECHO_REPLY* reply = reinterpret_cast<const ICMP_ECHO_REPLY*>(response.getBuffer());

                    duration = Duration::milliseconds(reply->RoundTripTime);
                }

                IcmpCloseHandle(icmpHandle);
            }

            return duration;
        }
    }
}