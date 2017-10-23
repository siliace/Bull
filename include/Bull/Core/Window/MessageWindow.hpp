#ifndef BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
#define BULL_CORE_WINDOW_MESSAGEWINDOW_HPP

#include <memory>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    struct BULL_CORE_API MessageWindow : public NonCopyable
    {
        enum Icon
        {
            Icon_None,
            Icon_Hand,
            Icon_Stop,
            Icon_Error,
            Icon_Warning,
            Icon_Asterisk,
            Icon_Question,
            Icon_Information,
            Icon_Exclamation,
        };

        enum Buttons
        {
            Buttons_Ok,
            Buttons_Help,
            Buttons_YesNo,
            Buttons_OkCancel,
            Buttons_RetryCancel,
            Buttons_YesNoCancel,
            Buttons_AbortRetryIgnore,
            Buttons_CancelTryContinue,
        };

        enum Response
        {
            Response_Ok,
            Response_No,
            Response_Yes,
            Response_Abort,
            Response_Retry,
            Response_Cancel,
            Response_Ignore,
            Response_Continue,
            Response_TryAgain,
        };

        enum DefaultButton
        {
            DefaultButton_Button1,
            DefaultButton_Button2,
            DefaultButton_Button3,
            DefaultButton_Button4,
        };

        /*! \brief Default constructor
         *
         */
        MessageWindow();

        /*! \brief Constructor
         *
         * \param message
         * \param title
         * \param parent
         *
         */
        MessageWindow(const String& message, const String& title, const Window* parent = nullptr);

        /*! \brief Open the MessageWindow
         *
         * \param message
         * \param title
         * \param parent
         *
         * \return
         *
         */
        Response open(const String& message, const String& title, const Window* parent = nullptr);

        Icon          icon;
        Buttons       buttons;
        DefaultButton defaultButton;
    };
}

#endif //BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
