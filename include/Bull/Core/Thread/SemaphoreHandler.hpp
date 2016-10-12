#ifndef Bull_SemaphoreHandler_hpp
#define Bull_SemaphoreHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
    typedef HANDLE SemaphoreHandler;
#else
    #error Lack of implementation : SemaphoreHandler
#endif

#endif // Bull_SemaphoreHandler_hpp
