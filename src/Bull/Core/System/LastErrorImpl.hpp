#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/System/Win32/LastErrorImpl.hpp>
#else
    #error lack of implementation : LastError
#endif // defined
