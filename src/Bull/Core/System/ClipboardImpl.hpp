#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Win32/ClipboardImpl.hpp>
#else
    #include <Bull/Core/System/Unix/ClipboardImpl.hpp>
#endif