#ifndef BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
#define BULL_CORE_WINDOW_MESSAGEWINDOW_HPP

#include <string>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    enum MessageWindowDefaultButton
    {
        MessageWindowDefaultButton_Button1,
        MessageWindowDefaultButton_Button2,
        MessageWindowDefaultButton_Button3,
        MessageWindowDefaultButton_Button4,
    };

    enum MessageWindowButtons
    {
        MessageWindowButtons_Ok,
        MessageWindowButtons_Help,
        MessageWindowButtons_YesNo,
        MessageWindowButtons_OkCancel,
        MessageWindowButtons_RetryCancel,
        MessageWindowButtons_YesNoCancel,
        MessageWindowButtons_AbortRetryIgnore,
        MessageWindowButtons_CancelTryContinue,
    };

    enum MessageWindowResponse
    {
        MessageWindowResponse_Ok,
        MessageWindowResponse_No,
        MessageWindowResponse_Yes,
        MessageWindowResponse_Abort,
        MessageWindowResponse_Retry,
        MessageWindowResponse_Cancel,
        MessageWindowResponse_Ignore,
        MessageWindowResponse_Continue,
        MessageWindowResponse_TryAgain,
    };

    enum MessageWindowIcon
    {
        MessageWindowIcon_None,
        MessageWindowIcon_Hand,
        MessageWindowIcon_Stop,
        MessageWindowIcon_Error,
        MessageWindowIcon_Warning,
        MessageWindowIcon_Asterisk,
        MessageWindowIcon_Question,
        MessageWindowIcon_Information,
        MessageWindowIcon_Exclamation,
    };

    class BULL_CORE_API MessageWindow : public NonCopyable
    {
    public:

        /** \brief Default constructor
         *
         */
        MessageWindow();

        /** \brief Constructor
         *
         * \param message The message to display in the MessageWindow
         * \param title   The title of the MessageWindow
         * \param parent  The parent Window
         *
         */
        MessageWindow(const std::string& message, const std::string& title, const Window* parent = nullptr);

        /** \brief Open the MessageWindow
         *
         * \param message The message to display in the MessageWindow
         * \param title   The title of the MessageWindow
         * \param parent  The parent Window
         *
         * \return The user's response
         *
         */
        MessageWindowResponse open(const std::string& message, const std::string& title, const Window* parent = nullptr);

    public:

        MessageWindowIcon icon;
        MessageWindowButtons buttons;
        MessageWindowDefaultButton defaultButton;
    };
}

#endif //BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
