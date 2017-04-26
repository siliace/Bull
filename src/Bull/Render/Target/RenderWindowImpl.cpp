#include <Bull/Core/System/Config.hpp>

#include <Bull/Render/Target/RenderWindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Target/X11/RenderWindowImplWin32>
    typedef Bull::prv::RenderWindowImplWin32 RenderWindowImplType;
#else
    #include <Bull/Render/Target/X11/RenderWindowImplX11.hpp>
    typedef Bull::prv::RenderWindowImplX11 RenderWindowImplType;
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
