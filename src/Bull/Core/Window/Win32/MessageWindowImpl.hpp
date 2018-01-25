#ifndef BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP
#define BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP

#include <Bull/Core/Memory/String.hpp>
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
            static MessageWindowResponse open(const String& message, const String& title, MessageWindowIcon icon, MessageWindowButtons buttons, MessageWindowDefaultButton defaultButton, WindowHandler parent);

        private:

            /*! \brief
             *
             * \param icon
             *
             * \return
             *
             */
            static UINT translateIcon(MessageWindowIcon icon);

            /*! \brief
             *
             * \param buttons
             *
             * \return
             *
             */
            static UINT translateButtons(MessageWindowButtons buttons);

            /*! \brief
             *
             * \param response
             *
             * \return
             *
             */
            static MessageWindowResponse translateResponse(int response);

            /*! \brief
             *
             * \param buttons
             *
             * \return
             *
             */
            static UINT translateDefaultButton(MessageWindowDefaultButton defaultButton);

        };
    }
}

#endif // BULL_CORE_WINDOW_WIN32_MESSAGEBOXIMPL_HPP
