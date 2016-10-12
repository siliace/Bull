#ifndef Bull_DirectoryHandler_hpp
#define Bull_DirectoryHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#else
    #include <dirent.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef HANDLE DirectoryHandler;
    #else
        typedef DIR* DirectoryHandler;
    #endif
}

#endif // Bull_DirectoryHandler_hpp
