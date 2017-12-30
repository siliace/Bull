#include <Bull/Render/Target/RenderWindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #error Lack of implementation : RenderWindow
#else
    #include <Bull/Render/Target/Xlib/RenderWindowImplXlib.hpp>
    typedef Bull::prv::RenderWindowImplXlib RenderWindowImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<WindowImpl> RenderWindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            return std::make_unique<RenderWindowImplType>(mode, title, style, settings);
        }
    }
}
