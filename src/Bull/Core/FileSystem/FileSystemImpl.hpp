#ifdef BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/FileSystemImpl.hpp>
#else
    #include <Bull/Core/FileSystem/Unix/FileSystemImpl.hpp>
#endif