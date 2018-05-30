#include <Bull/Core/Configuration/Macro.hpp>
#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Address/IpAddressImpl.hpp>
#include <Bull/Network/Socket/SocketHeader.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void IpAddressImpl::resolve(const String& hostname, NetProtocol protocol, std::vector<Uint8>& bytes, const String& service)
        {
            int error;
            addrinfo hints;
            addrinfo* info;

            BULL_ZERO_MEMORY(hints);

            hints.ai_family = SocketImpl::convertNetProtocol(protocol);

            error = getaddrinfo(hostname.getBuffer(), service.getBuffer(), &hints, &info);

            Expect(error == 0, Throw(InternalError, "IpAddressImpl::resolve", "Failed to get host address : " + String(gai_strerror(error))))

            SockAddrBuffer buffer((*info->ai_addr), info->ai_addrlen);
            const IpAddress& address = buffer.getIpAddress().getAddress();

            for(std::size_t i = 0; i < address.getByteCount(); i++)
            {
                bytes[i] = address.at(i);
            }

            freeaddrinfo(info);
        }
    }
}