#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Core/Window/Win32/MessageWindowImpl.hpp>

#else
    #include <Bull/Core/Window/Xlib/MessageWindowImpl.hpp>
#endif