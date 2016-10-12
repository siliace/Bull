#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/RAMImpl.hpp>
#else
    #error lack of implementation : RAM
#endif
