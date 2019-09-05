#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Network/Socket/Win32/SocketHeader.hpp>

#else
    #include <Bull/Network/Socket/Unix/SocketHeader.hpp>
#endif