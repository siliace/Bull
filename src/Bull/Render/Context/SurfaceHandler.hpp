#ifndef BULL_RENDER_CONTEXT_SURFACEHANDLER_HPP
#define BULL_RENDER_CONTEXT_SURFACEHANDLER_HPP

#include <Bull/Core/Prerequisites.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Support/Win32/Windows.hpp>
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

#endif // BULL_RENDER_CONTEXT_SURFACEHANDLER_HPP
