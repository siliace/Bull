#include <Bull/Core/Window/Win32/MessageWindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        MessageWindow::Response MessageWindowImpl::open(const String& message, const String& title, MessageWindow::Icon icon, MessageWindow::Buttons buttons, MessageWindow::DefaultButton defaultButton, WindowHandler parent)
        {
            UINT winIcon = translateIcon(icon);
            UINT winButtons = translateButtons(buttons);
            UINT winDefaultButton = translateDefaultButton(defaultButton);

            int response = MessageBox(parent,
                                      message.getBuffer(), title.getBuffer(),
                                      winIcon | winButtons | winDefaultButton | MB_APPLMODAL);

            return translateResponse(response);
        }

        UINT MessageWindowImpl::translateIcon(MessageWindow::Icon icon)
        {
            switch(icon)
            {
                case MessageWindow::Icon::Icon_None: return 0;
                case MessageWindow::Icon::Icon_Hand: return MB_ICONHAND;
                case MessageWindow::Icon::Icon_Stop: return MB_ICONSTOP;
                case MessageWindow::Icon::Icon_Error: return MB_ICONERROR;
                case MessageWindow::Icon::Icon_Warning: return MB_ICONWARNING;
                case MessageWindow::Icon::Icon_Asterisk: return MB_ICONASTERISK;
                case MessageWindow::Icon::Icon_Question: return MB_ICONQUESTION;
                case MessageWindow::Icon::Icon_Information: return MB_ICONINFORMATION;
                case MessageWindow::Icon::Icon_Exclamation: return MB_ICONEXCLAMATION;
            }

            return 0;
        }

        UINT MessageWindowImpl::translateButtons(MessageWindow::Buttons buttons)
        {
            switch(buttons)
            {
                case MessageWindow::Buttons::Buttons_Ok: return MB_OK;
                case MessageWindow::Buttons::Buttons_Help: return MB_HELP;
                case MessageWindow::Buttons::Buttons_YesNo: return MB_YESNO;
                case MessageWindow::Buttons::Buttons_OkCancel: return MB_OKCANCEL;
                case MessageWindow::Buttons::Buttons_RetryCancel: return MB_RETRYCANCEL;
                case MessageWindow::Buttons::Buttons_YesNoCancel: return MB_YESNOCANCEL;
                case MessageWindow::Buttons::Buttons_AbortRetryIgnore: return MB_ABORTRETRYIGNORE;
                case MessageWindow::Buttons::Buttons_CancelTryContinue: return MB_CANCELTRYCONTINUE;
            }

            return MB_OK;
        }

        MessageWindow::Response MessageWindowImpl::translateResponse(int response)
        {
            switch(response)
            {
                case IDOK: return MessageWindow::Response::Response_Ok;
                case IDNO: return MessageWindow::Response::Response_No;
                case IDYES: return MessageWindow::Response::Response_Yes;
                case IDABORT: return MessageWindow::Response::Response_Abort;
                case IDRETRY: return MessageWindow::Response::Response_Retry;
                case IDCANCEL: return MessageWindow::Response::Response_Cancel;
                case IDIGNORE: return MessageWindow::Response::Response_Ignore;
                case IDCONTINUE: return MessageWindow::Response::Response_Continue;
                case IDTRYAGAIN: return MessageWindow::Response::Response_TryAgain;
            }

            return MessageWindow::Response::Response_Ok;
        }

        UINT MessageWindowImpl::translateDefaultButton(MessageWindow::DefaultButton defaultButton)
        {
            switch(defaultButton)
            {
                case MessageWindow::DefaultButton::DefaultButton_Button1: return MB_DEFBUTTON1;
                case MessageWindow::DefaultButton::DefaultButton_Button2: return MB_DEFBUTTON2;
                case MessageWindow::DefaultButton::DefaultButton_Button3: return MB_DEFBUTTON3;
                case MessageWindow::DefaultButton::DefaultButton_Button4: return MB_DEFBUTTON4;
            }

            return MB_DEFBUTTON1;
        }
    }
}