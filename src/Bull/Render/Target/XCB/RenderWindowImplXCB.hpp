#ifndef BULL_RENDERWINDOWIMPLXCB_HPP
#define BULL_RENDERWINDOWIMPLXCB_HPP

#include <Bull/Window/XCB/WindowImplXCB.hpp>

namespace Bull
{
    namespace prv
    {
        class RenderWindowImplXCB : public WindowImplXCB
        {
        public:

            RenderWindowImplXCB(const VideoMode& mode, const String& title, Uint32 WindowStyle, const ContextSettings& settings);
        };
    }
}

#endif //BULL_RENDERWINDOWIMPLXCB_HPP
