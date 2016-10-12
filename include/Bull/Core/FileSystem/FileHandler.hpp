#ifndef Bull_FileHandler_hpp
#define Bull_FileHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef HANDLE FileHandler;
    #else
        typedef int FileHandler;
    #endif
}

#endif // Bull_FileHandler_hpp
