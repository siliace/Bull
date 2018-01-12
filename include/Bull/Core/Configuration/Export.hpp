#ifndef BULL_CORE_CONFIGURATION_EXPORT_hpp
#define BULL_CORE_CONFIGURATION_EXPORT_hpp

#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_DYNAMIC
    #if defined BULL_OS_WINDOWS
        #define BULL_API_EXPORT __declspec(dllexport)
        #define BULL_API_IMPORT __declspec(dllimport)
    #else
        #if BULL_COMPLER == BULL_COMPILER_GCC
            #if BULL_COMPILER_VERSION >= 4
                #define BULL_API_EXPORT __attribute__ ((__visibility__ ("default")))
                #define BULL_API_IMPORT __attribute__ ((__visibility__ ("default")))
            #else
                #define BULL_API_EXPORT
                #define BULL_API_IMPORT
            #endif
        #endif
     #endif
#else
    #define BULL_API_EXPORT
    #define BULL_API_IMPORT
#endif


#endif // BULL_CORE_CONFIGURATION_EXPORT_hpp
