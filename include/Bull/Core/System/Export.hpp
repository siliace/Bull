#ifndef Bull_Export_hpp
#define Bull_Export_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_DYNAMIC
    #if defined BULL_OS_WINDOWS
        #if defined BULL_BUILD
            #define BULL_API __declspec(dllexport)
        #else
            #define BULL_API __declspec(dllimport)
        #endif
    #else
        #error Lack of export to .so compilation
    #endif
#else
    #define BULL_API
#endif


#endif // Bull_Core_Export_hpp
