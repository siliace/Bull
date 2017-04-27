#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Hardware/Win32/KeyboardImpl.hpp>
#else
    #include <Bull/Hardware/Unix/KeyboardImpl.hpp>
#endif
