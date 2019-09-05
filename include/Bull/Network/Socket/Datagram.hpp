#ifndef BULL_NETWORK_SOCKET_DATAGRAM_HPP
#define BULL_NETWORK_SOCKET_DATAGRAM_HPP

#include <memory>

#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Network/Address/IpAddress.hpp>
#include <Bull/Network/Address/NetPort.hpp>

namespace Bull
{
    struct BULL_NETWORK_API Datagram
    {
        NetPort port;
        ByteArray bytes;
        std::unique_ptr<IpAddress> address;
    };
}

#endif // BULL_NETWORK_SOCKET_DATAGRAM_HPP
