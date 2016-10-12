#ifndef Bull_ThreadHandler_hpp
#define Bull_ThreadHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#else
    #include <pthread.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef HANDLE ThreadHandler;
    #else
        typedef pthread_t ThreadHandler;
    #endif
}

#endif // Bull_ThreadHandler_hpp


