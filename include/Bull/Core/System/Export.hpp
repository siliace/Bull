#ifndef Bull_Export_hpp
#define Bull_Export_hpp

#include <Bull/Core/System/OS.hpp>

#if defined BULL_DYNAMIC
    #if defined BULL_OS_WINDOWS
        #define EXPORT_SYMBOL __declspec(dllexport)
        #define IMPORT_SYMBOM __declspec(dllimport)
    #else
        #if __GNUC__ >= 4
            #define EXPORT_SYMBOL __attribute__ ((__visibility__ ("default")))
            #define IMPORT_SYMBOM __attribute__ ((__visibility__ ("default")))
        #else
            #define EXPORT_SYMBOL
            #define IMPORT_SYMBOM
        #endif
    #endif
    #if defined BULL_BUILD
        #define BULL_API EXPORT_SYMBOL
    #else
        #define BULL_API IMPORT_SYMBOM
    #endif
#else
    #define BULL_API
#endif


#endif // Bull_Core_Export_hpp
