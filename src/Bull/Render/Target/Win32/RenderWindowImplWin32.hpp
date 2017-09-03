#ifndef BULL_RENDERWINDOWIMPLWIN32_HPP
#define BULL_RENDERWINDOWIMPLWIN32_HPP

#include <Bull/Window/Win32/WindowImplWin32.hpp>

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
             * \param WindowStyle
             * \param settings
             *
             */
            RenderWindowImplWin32(const VideoMode& mode, const String& title, Uint32 WindowStyle, const ContextSettings& settings);
        };
    }
}

#endif //BULL_RENDERWINDOWIMPLWIN32_HPP
