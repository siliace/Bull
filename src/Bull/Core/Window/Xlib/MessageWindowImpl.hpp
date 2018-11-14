#ifndef BULL_CORE_WINDOW_XLIB_MESSAGEWINDOWIMPL_HPP
#define BULL_CORE_WINDOW_XLIB_MESSAGEWINDOWIMPL_HPP

#include <Bull/Core/Window/MessageWindow.hpp>
#include <Bull/Core/Window/WindowHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class MessageWindowImpl
        {
        public:

            /*! \brief
             *
             * \param message
             * \param title
             * \param parent
             *
             * \return
             *
             */
            static MessageWindowResponse open(const String& message, const String& title, MessageWindowIcon icon, MessageWindowButtons buttons, MessageWindowDefaultButton defaultButton, WindowHandler parent);
        };
    }
}

#endif // BULL_CORE_WINDOW_XLIB_MESSAGEWINDOWIMPL_HPP
