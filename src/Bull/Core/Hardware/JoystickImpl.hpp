#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Hardware/Win32/JoystickImpl.hpp>
#else
    #include <Bull/Core/Hardware/Unix/JoystickImpl.hpp>
#endif
