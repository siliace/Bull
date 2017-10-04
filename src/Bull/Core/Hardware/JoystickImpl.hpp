#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Win32/JoystickImpl.hpp>
#else
    #include <Bull/Core/Hardware/Unix/JoystickImpl.hpp>
#endif
