#include <Bull/Core/Window/Win32/MessageWindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        MessageWindowResponse MessageWindowImpl::open(const std::string& message, const std::string& title, MessageWindowIcon icon, MessageWindowButtons buttons, MessageWindowDefaultButton defaultButton, WindowHandler parent)
        {
            UINT winIcon = translateIcon(icon);
            UINT winButtons = translateButtons(buttons);
            UINT winDefaultButton = translateDefaultButton(defaultButton);

            int response = MessageBox(parent,
                                      message.c_str(), title.c_str(),
                                      winIcon | winButtons | winDefaultButton | MB_APPLMODAL);

            return translateResponse(response);
        }

        UINT MessageWindowImpl::translateIcon(MessageWindowIcon icon)
        {
            switch(icon)
            {
                case MessageWindowIcon_None:
                    return 0;
                case MessageWindowIcon_Hand:
                    return MB_ICONHAND;
                case MessageWindowIcon_Stop:
                    return MB_ICONSTOP;
                case MessageWindowIcon_Error:
                    return MB_ICONERROR;
                case MessageWindowIcon_Warning:
                    return MB_ICONWARNING;
                case MessageWindowIcon_Asterisk:
                    return MB_ICONASTERISK;
                case MessageWindowIcon_Question:
                    return MB_ICONQUESTION;
                case MessageWindowIcon_Information:
                    return MB_ICONINFORMATION;
                case MessageWindowIcon_Exclamation:
                    return MB_ICONEXCLAMATION;
            }

            return 0;
        }

        UINT MessageWindowImpl::translateButtons(MessageWindowButtons buttons)
        {
            switch(buttons)
            {
                case MessageWindowButtons_Ok:
                    return MB_OK;
                case MessageWindowButtons_Help:
                    return MB_HELP;
                case MessageWindowButtons_YesNo:
                    return MB_YESNO;
                case MessageWindowButtons_OkCancel:
                    return MB_OKCANCEL;
                case MessageWindowButtons_RetryCancel:
                    return MB_RETRYCANCEL;
                case MessageWindowButtons_YesNoCancel:
                    return MB_YESNOCANCEL;
                case MessageWindowButtons_AbortRetryIgnore:
                    return MB_ABORTRETRYIGNORE;
                case MessageWindowButtons_CancelTryContinue:
                    return MB_CANCELTRYCONTINUE;
            }

            return MB_OK;
        }

        MessageWindowResponse MessageWindowImpl::translateResponse(int response)
        {
            switch(response)
            {
                case IDOK:
                    return MessageWindowResponse_Ok;
                case IDNO:
                    return MessageWindowResponse_No;
                case IDYES:
                    return MessageWindowResponse_Yes;
                case IDABORT:
                    return MessageWindowResponse_Abort;
                case IDRETRY:
                    return MessageWindowResponse_Retry;
                case IDCANCEL:
                    return MessageWindowResponse_Cancel;
                case IDIGNORE:
                    return MessageWindowResponse_Ignore;
                case IDCONTINUE:
                    return MessageWindowResponse_Continue;
                case IDTRYAGAIN:
                    return MessageWindowResponse_TryAgain;
            }

            return MessageWindowResponse_Ok;
        }

        UINT MessageWindowImpl::translateDefaultButton(MessageWindowDefaultButton defaultButton)
        {
            switch(defaultButton)
            {
                case MessageWindowDefaultButton_Button1:
                    return MB_DEFBUTTON1;
                case MessageWindowDefaultButton_Button2:
                    return MB_DEFBUTTON2;
                case MessageWindowDefaultButton_Button3:
                    return MB_DEFBUTTON3;
                case MessageWindowDefaultButton_Button4:
                    return MB_DEFBUTTON4;
            }

            return MB_DEFBUTTON1;
        }
    }
}