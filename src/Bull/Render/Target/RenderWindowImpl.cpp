#include <Bull/Render/Target/RenderWindowImpl.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Render/Target/Win32/RenderWindowImplWin32.hpp>

typedef Bull::prv::RenderWindowImplWin32 RenderWindowImplType;
#else
    #include <Bull/Render/Target/Xlib/RenderWindowImplXlib.hpp>
typedef Bull::prv::RenderWindowImplXlib RenderWindowImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<WindowImpl> RenderWindowImpl::createInstance(const VideoMode& mode, const std::string& title, Uint32 style, const ContextSettings& settings)
        {
            return std::make_unique<RenderWindowImplType>(mode, title, style, settings);
        }
    }
}
