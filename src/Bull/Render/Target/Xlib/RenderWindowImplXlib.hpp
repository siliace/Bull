#ifndef BULL_RENDER_TARGET_RENDERWINDOWIMPLXLIB_HPP
#define BULL_RENDER_TARGET_RENDERWINDOWIMPLXLIB_HPP

#include <Bull/Core/Window/Xlib/WindowImplXlib.hpp>

#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImplXlib : public WindowImplXlib
        {
            /*! \brief Constructor
             *
             * \param mode     The VideoMode of the RenderWindow
             * \param title    The title of the RenderWindow
             * \param style    The WindowStyle of the RenderWindow
             * \param settings ContextSettings to use to create the GlContext
             *
             */
            RenderWindowImplXlib(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);
        };
    }
}

#endif //BULL_RENDERWINDOWIMPLXLIB_HPP
