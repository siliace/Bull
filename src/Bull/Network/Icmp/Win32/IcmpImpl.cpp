#include <iphlpapi.h>
#include <icmpapi.h>

#include <Bull/Core/Support/Win32/Win32Error.hpp>

#include <Bull/Network/Icmp/Win32/IcmpImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Duration IcmpImpl::ping(const IpAddressV4& address, const Duration& timeout)
        {
            HANDLE icmpHandle = IcmpCreateFile();

            Expect(icmpHandle != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to create ICMP handler"));

            ByteArray request(32);
            IPAddr addr = address.toInt();
            ByteArray response(sizeof(ICMP_ECHO_REPLY) + request.getCapacity());

            DWORD retval = IcmpSendEcho(icmpHandle, addr, &request[0], request.getCapacity(), nullptr, &response[0], response.getCapacity(), timeout.asMilliseconds());

            Expect(retval > 0, Throw(Win32Error, "Failed to send ICMP request"));

            const ICMP_ECHO_REPLY* reply = reinterpret_cast<const ICMP_ECHO_REPLY*>(response.getBuffer());

            Duration duration = Duration::milliseconds(reply->RoundTripTime);

            IcmpCloseHandle(icmpHandle);

            return duration;
        }
    }
}