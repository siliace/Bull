#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/System/Win32/ClipboardImpl.hpp>
#else
    #error Lack of implementation : Clipboard
#endif