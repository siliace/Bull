#ifndef BULL_CORE_THREAD_MUTEXHANDLER_HPP
#define BULL_CORE_THREAD_MUTEXHANDLER_HPP

#include <Bull/Core/System/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#endif

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef CRITICAL_SECTION MutexHandler;
        #else
            typedef pthread_mutex_t MutexHandler;
        #endif
    }
}

#endif // BULL_CORE_THREAD_MUTEXHANDLER_HPP
