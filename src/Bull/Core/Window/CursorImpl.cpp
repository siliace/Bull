#include <Bull/Core/Configuration/OS.hpp>

#include <Bull/Core/Window/CursorImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Window/Win32/CursorImplWin32.hpp>
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
        #include <Bull/Core/Window/Xlib/CursorImplXlib.hpp>
        typedef Bull::prv::CursorImplXlib CursorImplType;
    #else
        #error Lack of implementation : Cursor
    #endif
#endif

namespace Bull
{
    namespace prv
    {
        ImplPtr<CursorImpl> CursorImpl::createInstance()
        {
            return ImplPtr<CursorImpl>::make<CursorImplType>();
        }

        CursorImpl::~CursorImpl() = default;
    }
}