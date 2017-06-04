#include <Bull/Core/System/OS.hpp>

#include <Bull/Window/CursorImpl.hpp>

#if defined BULL_OS_WINDOWS
    #error Lack of implementation : Cursor
#elif defined BULL_OS_OSX
    #error Lack of implementation : Cursor
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_WEYLAND
        #error Lack of implementation : Cursor
    #elif defined BULL_XCB
        #error Lack of implementation : Cursor
    #elif defined BULL_XLIB
        #include <Bull/Window/Xlib/CursorImplXlib.hpp>
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

        CursorImpl::~CursorImpl()
        {
            /// Nothing
        }
    }
}