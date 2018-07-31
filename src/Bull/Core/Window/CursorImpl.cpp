#include <Bull/Core/Window/CursorImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Window/Win32/CursorImplWin32.hpp>
    typedef Bull::prv::CursorImplWin32 CursorImplType;
#elif defined BULL_OS_OSX
    #error Lack of implementation : Cursor
#elif defined BULL_OS_GNU_LINUX
    #include <Bull/Core/Window/Xlib/CursorImplXlib.hpp>
    typedef Bull::prv::CursorImplXlib CursorImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<CursorImpl> CursorImpl::createInstance()
        {
            return std::make_unique<CursorImplType>();
        }

        CursorImpl::~CursorImpl() = default;
    }
}