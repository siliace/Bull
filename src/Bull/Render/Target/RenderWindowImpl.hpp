#ifndef BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP
#define BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP

#include <Bull/Core/Window/WindowImpl.hpp>

#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImpl : public NonCopyable
        {
            static std::unique_ptr<WindowImpl> createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);
        };
    }
}

#endif // BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP
