#ifndef BULL_RENDERWINDOWIMPL_HPP
#define BULL_RENDERWINDOWIMPL_HPP

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
             * \param style    The style to use to create the window
             * \param settings Settings to use to create the OpenGL context
             *
             * \return Return the created instance
             *
             */
            static WindowImpl* createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            virtual ~RenderWindowImpl();
        };
    }
}

#endif //BULL_RENDERWINDOWIMPL_HPP
