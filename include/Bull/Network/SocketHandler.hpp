#ifndef BULL_NETWORK_SOCKETHANDLER_HPP
#define BULL_NETWORK_SOCKETHANDLER_HPP

#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <basetsd.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef UINT_PTR SocketHandler;
    #else
        typedef int SocketHandler;
    #endif
}

#endif // BULL_NETWORK_SOCKETHANDLER_HPP
