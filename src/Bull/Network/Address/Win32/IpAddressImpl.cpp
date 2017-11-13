#include <Bull/Core/Configuration/Macro.hpp>

#include <Bull/Network/Address/SockAddrBuffer.hpp>
#include <Bull/Network/Address/Win32/IpAddressImpl.hpp>
#include <Bull/Network/Socket/SocketImpl.hpp>

namespace Bull
{
    namespace prv
    {
        bool IpAddressImpl::resolve(const String& hostname, NetProtocol protocol, ByteVector& bytes, const String& service)
        {
            addrinfo hints;
            addrinfo* info;

            BULL_ZERO_MEMORY(hints);

            hints.ai_protocol = SocketImpl::convertNetProtocol(protocol);

            if(getaddrinfo(hostname.getBuffer(), service.getBuffer(), &hints, &info) == 0)
            {
                SockAddrBuffer buffer((*info->ai_addr), info->ai_addrlen);
                const IpAddress& address = buffer.getIpAddress().getAddress();

                for(std::size_t i = 0; i < address.getByteCount(); i++)
                {
                    bytes[i] = address.at(i);
                }

                return true;
            }

            return false;
        }
    }
}