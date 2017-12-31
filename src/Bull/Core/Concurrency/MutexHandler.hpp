#ifndef BULL_CORE_CONCURRENCY_MUTEXHANDLER_HPP
#define BULL_CORE_CONCURRENCY_MUTEXHANDLER_HPP

#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Support/Win32/Windows.hpp>
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

#endif // BULL_CORE_CONCURRENCY_MUTEXHANDLER_HPP
