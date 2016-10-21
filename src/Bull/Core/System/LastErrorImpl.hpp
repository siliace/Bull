#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/System/Win32/LastErrorImpl.hpp>
#else
    #include <Bull/Core/System/Unix/LastErrorImpl.hpp>
#endif // defined
