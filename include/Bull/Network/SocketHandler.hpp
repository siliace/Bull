#ifndef BULL_SOCKETHANDLER_HPP
#define BULL_SOCKETHANDLER_HPP

#include <Bull/Core/System/Config.hpp>

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef unsigned long long SocketHandler;
    #else
        typedef int SocketHandler;
    #endif
}

#endif // BULL_SOCKETHANDLER_HPP
