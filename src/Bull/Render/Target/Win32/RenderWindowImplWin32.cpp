#include <Bull/Render/Target/Win32/RenderWindowImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        RenderWindowImplWin32::RenderWindowImplWin32(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& /*settings*/) :
            WindowImplWin32(mode, title, style)
        {
            /// Nothing
        }
    }
}