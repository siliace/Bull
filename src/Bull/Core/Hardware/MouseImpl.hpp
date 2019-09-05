#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Core/Hardware/Win32/MouseImpl.hpp>

#else
    #include <Bull/Core/Hardware/Xlib/MouseImpl.hpp>
#endif
