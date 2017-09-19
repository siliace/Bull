#ifndef Bull_SurfaceHandler_hpp
#define Bull_SurfaceHandler_hpp

#include <Bull/Core/Configuration/OS.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#endif

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef HDC SurfaceHandler;
        #else
            typedef int SurfaceHandler;
        #endif
    }
}

#endif // Bull_SurfaceHandler_hpp
