#ifndef BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP
#define BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
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
            static MessageWindow::Response open(const String& message, const String& title, MessageWindow::Icon icon, MessageWindow::Buttons buttons, MessageWindow::DefaultButton defaultButton, WindowHandler parent);

        private:

            /*! \brief
             *
             * \param icon
             *
             * \return
             *
             */
            static UINT translateIcon(MessageWindow::Icon icon);

            /*! \brief
             *
             * \param buttons
             *
             * \return
             *
             */
            static UINT translateButtons(MessageWindow::Buttons buttons);

            /*! \brief
             *
             * \param response
             *
             * \return
             *
             */
            static MessageWindow::Response translateResponse(int response);

            /*! \brief
             *
             * \param buttons
             *
             * \return
             *
             */
            static UINT translateDefaultButton(MessageWindow::DefaultButton defaultButton);

        };
    }
}

#endif // BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP
