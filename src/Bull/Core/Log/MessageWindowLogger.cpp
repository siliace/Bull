#include <Bull/Core/Configuration/Macro.hpp>
#include <Bull/Core/Log/MessageWindowLogger.hpp>

namespace Bull
{
    MessageWindowIcon MessageWindowLogger::chooseIcon(LogLevel level)
    {
        switch(level)
        {
            case LogLevel_Debug:   return MessageWindowIcon_Hand;
            case LogLevel_Error:   return MessageWindowIcon_Error;
            case LogLevel_Warning: return MessageWindowIcon_Warning;
            case LogLevel_Info:    return MessageWindowIcon_Information;
        }
    }

    MessageWindowLogger::MessageWindowLogger()
    {
        m_messageBox.buttons       = MessageWindowButtons_Ok;
        m_messageBox.defaultButton = MessageWindowDefaultButton_Button1;
    }

    void MessageWindowLogger::write(const String& entry)
    {
        m_messageBox.open(entry, m_title);
    }

    String MessageWindowLogger::formatEntry(const String& entry, LogLevel level, const Date& date)
    {
        BULL_UNUSED(date);

        m_title = logLevelToString(level);
        m_messageBox.icon = chooseIcon(level);

        return entry;
    }
}