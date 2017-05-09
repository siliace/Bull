#include <Bull/Core/System/OS.hpp>

#include <Bull/Render/Target/RenderWindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Target/Win32/RenderWindowImplWin32.hpp>
    typedef Bull::prv::RenderWindowImplWin32 RenderWindowImplType;
#else
    #if defined BULL_XLIB
        #include <Bull/Render/Target/Xlib/RenderWindowImplXlib.hpp>
        typedef Bull::prv::RenderWindowImplXlib RenderWindowImplType;
    #elif defined BULL_XCB
        #include <Bull/Render/Target/XCB/RenderWindowImplXCB.hpp>
        typedef Bull::prv::RenderWindowImplXCB RenderWindowImplType;
    #elif defined BULL_WAYLAND
        #error Todo
    #endif
#endif

namespace Bull
{
    namespace prv
    {
        WindowImpl* RenderWindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            return new RenderWindowImplType(mode, title, style, settings);
        }

        RenderWindowImpl::~RenderWindowImpl()
        {
            /// Nothing
        }
    }
}
