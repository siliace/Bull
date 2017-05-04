#ifndef BULL_SYSTEMEXPORT_hpp
#define BULL_SYSTEMEXPORT_hpp

#include <Bull/Core/System/OS.hpp>

#if defined BULL_DYNAMIC
    #if defined BULL_OS_WINDOWS
        #define BULL_API_EXPORT __declspec(dllexport)
        #define BULL_API_IMPORT __declspec(dllimport)
    #else
        #if __GNUC__ >= 4
            #define BULL_API_EXPORT __attribute__ ((__visibility__ ("default")))
            #define BULL_API_IMPORT __attribute__ ((__visibility__ ("default")))
        #else
            #define BULL_API_EXPORT
            #define BULL_API_IMPORT
        #endif
    #endif
#else
    #define BULL_CORE_API
#endif


#endif // BULL_SYSTEMEXPORT_hpp
