#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/MouseImpl.hpp>
#else
    #include <Bull/Hardware/Unix/MouseImpl.hpp>
#endif
