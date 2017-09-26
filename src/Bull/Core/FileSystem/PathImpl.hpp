#include <Bull/Core/Configuration/OS.hpp>

#ifdef BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#else
    #include <Bull/Core/FileSystem/Unix/PathImpl.hpp>
#endif