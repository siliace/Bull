#ifndef Bull_SemaphoreHandler_hpp
#define Bull_SemaphoreHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
    typedef HANDLE SemaphoreHandler;
#else
    #include <semaphore.h>
    typedef sem_t SemaphoreHandler;
#endif

#endif // Bull_SemaphoreHandler_hpp
