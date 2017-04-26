#ifndef BULL_RENDERWINDOWIMPLX11_HPP
#define BULL_RENDERWINDOWIMPLX11_HPP

#include <Bull/Window/X11/WindowImplX11.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImplX11 : public WindowImplX11
        {
            /*! \brief Constructor
             *
             * \param mode
             * \param title
             * \param style
             * \param settings
             *
             */
            RenderWindowImplX11(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);
        };
    }
}

#endif // BULL_RENDERWINDOWIMPLX11_HPP