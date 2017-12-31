#ifndef BULL_RENDERWINDOWIMPLWIN32_HPP
#define BULL_RENDERWINDOWIMPLWIN32_HPP

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
             * \param mode
             * \param title
             * \param style
             *
             */
            RenderWindowImplWin32(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& /*settings*/);
        };
    }
}

#endif //BULL_RENDERWINDOWIMPLWIN32_HPP
