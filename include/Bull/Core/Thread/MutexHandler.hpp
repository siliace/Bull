#ifndef Bull_MutexHandler_hpp
#define Bull_MutexHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#else
    #include <pthread.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef CRITICAL_SECTION MutexHandler;
    #else
        typedef pthread_mutex_t MutexHandler;
    #endif
}

#endif // Bull_MutexHandler_hpp

