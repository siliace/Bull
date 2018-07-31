#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Hardware/Win32/KeyboardImpl.hpp>
#elif defined BULL_OS_GNU_LINUX
    #include <Bull/Core/Hardware/Xlib/KeyboardImpl.hpp>
#endif
