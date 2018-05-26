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
            /*! \brief Create an OS specific implementation of RenderWindowImpl
             *
             * \param mode     The VideoMode of the RenderWindow
             * \param title    The title of the RenderWindow
             * \param style    The WindowStyle of the RenderWindow
             * \param settings ContextSettings to use to create the GlContext
             *
             * \return The create instance
             *
             */
            static std::unique_ptr<WindowImpl> createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);
        };
    }
}

#endif // BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP
