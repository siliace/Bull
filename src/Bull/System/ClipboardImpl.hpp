#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/ClipboardImpl.hpp>
#else
    #include <Bull/System/Unix/ClipboardImpl.hpp>
#endif