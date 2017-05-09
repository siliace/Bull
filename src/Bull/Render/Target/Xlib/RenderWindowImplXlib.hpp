#ifndef BULL_RENDERWINDOWIMPLXLIB_HPP
#define BULL_RENDERWINDOWIMPLXLIB_HPP

#include <Bull/Window/Xlib/WindowImplXlib.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImplXlib : public WindowImplXlib
        {
            /*! \brief Constructor
             *
             * \param mode
             * \param title
             * \param style
             * \param settings
             *
             */
            RenderWindowImplXlib(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);
        };
    }
}

#endif // BULL_RENDERWINDOWIMPLXLIB_HPP