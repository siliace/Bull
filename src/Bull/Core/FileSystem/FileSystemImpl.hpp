#include <Bull/Core/Configuration/OS.hpp>

#ifdef BULL_OS_WINDOWS
    #error Lack of implementation : FileSystem
#else
    #include <Bull/Core/FileSystem/Unix/FileSystemImpl.hpp>
#endif