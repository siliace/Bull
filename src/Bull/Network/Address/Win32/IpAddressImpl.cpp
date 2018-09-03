#include <Bull/Core/Support/Win32/Win32Error.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Address/Win32/IpAddressImpl.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        ByteArray IpAddressImpl::resolve(const String& hostname, NetProtocol protocol, const String& service)
        {
            int error;
            addrinfo hints;
            addrinfo* info;
            ByteArray bytes;

            BULL_ZERO_MEMORY(hints);

            hints.ai_family = SocketImpl::convertNetProtocol(protocol);

            error = getaddrinfo(hostname.getBuffer(), service.getBuffer(), &hints, &info);

            Expect(error == 0, Throw(Win32Error, "IpAddressImpl::resolve", "Failed to resolve hostname " + hostname));

            SockAddrBuffer buffer((*info->ai_addr), info->ai_addrlen);
            std::unique_ptr<IpAddress> address = buffer.getIpAddress();

            for(std::size_t i = 0; i < address->getByteCount(); i++)
            {
                bytes[i] = address->at(i);
            }

            freeaddrinfo(info);

            return bytes;
        }
    }
}