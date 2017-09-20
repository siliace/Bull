#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Network/Win32/IcmpImpl.hpp>
#include <Bull/Network/Win32/IpAddressImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time IcmpImpl::ping(const IpAddress& host, const Time& timeout)
        {
            switch(host.getProtocol())
            {
                case IpAddress::IpV4:
                {
                    return ping(host.toUint32(), timeout);
                }

                case IpAddress::IpV6:
                {
                    IpAddressImpl::SockAddrBuffer sockAddr;
                    IpAddressImpl::SockAddrLenght length = IpAddressImpl::toSockAddr(host, Socket::AnyPort, &sockAddr[0]);

                    if(length > 0)
                    {
                        return ping(reinterpret_cast<const sockaddr_in6*>(&sockAddr[0]), timeout);
                    }
                }
            }

            return Time::Zero;
        }

        Time IcmpImpl::ping(Uint32 host, const Time& timeout)
        {
            IPAddr addr = host;
            ByteArray requestBuffer(32);
            ByteArray responseBuffer(1024); /// Let's be generous
            HANDLE icmp = IcmpCreateFile();
            Time responseTime = Time::Zero;

            DWORD responseCount = IcmpSendEcho(icmp, addr,
                                               &requestBuffer[0], static_cast<WORD>(requestBuffer.getCapacity()),
                                               nullptr,
                                               &responseBuffer[0], static_cast<WORD>(responseBuffer.getCapacity()),
                                               static_cast<DWORD>(timeout.asMilliseconds()));

            if(responseCount)
            {
                const icmp_echo_reply* reply = reinterpret_cast<const icmp_echo_reply*>(responseBuffer.getBuffer());

                responseTime = Time::milliseconds(reply->RoundTripTime);
            }

            return responseTime;
        }

        Time IcmpImpl::ping(const sockaddr_in6* host, const Time& timeout)
        {
            return Time::Zero;
        }
    }
}