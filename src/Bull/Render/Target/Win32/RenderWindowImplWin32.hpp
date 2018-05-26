#ifndef BULL_RENDER_TARGET_RENDERWINDOWIMPLWIN32_HPP
#define BULL_RENDER_TARGET_RENDERWINDOWIMPLWIN32_HPP

#include <Bull/Core/Window/Win32/WindowImplWin32.hpp>

#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    namespace prv
    {
        struct RenderWindowImplWin32 : public WindowImplWin32
        {
            /*! \brief Constructor
             *
             * \param mode  The VideoMode of the RenderWindow
             * \param title The title of the RenderWindow
             * \param style The WindowStyle of the RenderWindow
             *
             */
            RenderWindowImplWin32(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& /*settings*/);
        };
    }
}

#endif // BULL_RENDER_TARGET_RENDERWINDOWIMPLWIN32_HPP
