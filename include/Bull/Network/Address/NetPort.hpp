#ifndef BULL_SOCKET_ADDRESS_NETPORT_HPP
#define BULL_SOCKET_ADDRESS_NETPORT_HPP

namespace Bull
{
    enum NetPort : unsigned short
    {
        NetPort_Any = 0,
        NetPort_Http = 80,
        NetPort_Https = 443,
    };
}

#endif // BULL_SOCKET_ADDRESS_NETPORT_HPP
