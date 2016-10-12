#ifndef Bull_LocalHandler_hpp
#define Bull_LocalHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_UNIX
    #include <pthread.h>
#endif

namespace Bull
{
    #if defined BULL_OS_WINDOWS
        typedef unsigned long LocalHandler;
    #else
        typedef pthread_key_t LocalHandler;
    #endif
}

#endif // Bull_LocalHandler_hpp
