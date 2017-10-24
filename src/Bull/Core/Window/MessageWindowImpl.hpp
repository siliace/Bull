#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Window/Win32/MessageWindowImpl.hpp>
#else
    #error Lack of implementation : MessageBox
#endif