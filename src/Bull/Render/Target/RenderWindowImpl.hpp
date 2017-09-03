#ifndef BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP
#define BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP

#include <Bull/Render/Context/ContextSettings.hpp>

#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImpl : public NonCopyable
        {
            /*! \brief Create a OS specific WindowImpl instance
             *
             * \param mode     The VideoMode to use to create the window
             * \param title    The title of the window
             * \param WindowStyle    The WindowStyle to use to create the window
             * \param settings Settings to use to create the OpenGL context
             *
             * \return Return the created instance
             *
             */
            static WindowImpl* createInstance(const VideoMode& mode, const String& title, Uint32 WindowStyle, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            virtual ~RenderWindowImpl();
        };
    }
}

#endif // BULL_RENDER_TARGET_RENDERWINDOWIMPL_HPP
