#ifndef Bull_SurfaceHandler_hpp
#define Bull_SurfaceHandler_hpp

#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <windows.h>
#endif

namespace Bull
{
    namespace prv
    {
        #if defined BULL_OS_WINDOWS
            typedef HDC SurfaceHandler;
        #endif
    }
}

#endif // Bull_SurfaceHandler_hpp
