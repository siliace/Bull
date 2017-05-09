#include <Bull/Render/Target/XCB/RenderWindowImplXCB.hpp>

namespace Bull
{
    namespace prv
    {
        RenderWindowImplXCB::RenderWindowImplXCB(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings) :
            WindowImplXCB(mode, title, style)
        {
            /// Nothing
        }
    }
}