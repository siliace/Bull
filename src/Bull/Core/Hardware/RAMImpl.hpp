#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Core/Hardware/Win32/RAMImpl.hpp>

#else
    #include <Bull/Core/Hardware/Unix/RAMImpl.hpp>
#endif
