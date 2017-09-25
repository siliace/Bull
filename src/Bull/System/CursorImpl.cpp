#include <Bull/Core/Configuration/OS.hpp>

#include <Bull/System/CursorImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/CursorImplWin32.hpp>
    typedef Bull::prv::CursorImplWin32 CursorImplType;
#elif defined BULL_OS_OSX
    #error Lack of implementation : Cursor
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_WEYLAND
        #error Lack of implementation : Cursor
    #elif defined BULL_XCB
        #include <Bull/Window/XCB/CursorImplXCB.hpp>
        typedef Bull::prv::CursorImplXCB CursorImplType;
    #elif defined BULL_XLIB
        #include <Bull/System/Xlib/CursorImplXlib.hpp>
        typedef Bull::prv::CursorImplXlib CursorImplType;
    #else
        #error Lack of implementation : Cursor
    #endif
#endif

namespace Bull
{
    namespace prv
    {
        CursorImpl* CursorImpl::createInstance()
        {
            return new CursorImplType();
        }

        CursorImpl::~CursorImpl() = default;
    }
}