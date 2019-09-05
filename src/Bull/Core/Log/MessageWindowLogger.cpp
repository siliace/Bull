#include <Bull/Core/Log/MessageWindowLogger.hpp>

namespace Bull
{
    MessageWindowIcon MessageWindowLogger::chooseIcon(LogLevel level)
    {
        switch(level)
        {
            case LogLevel_Debug:
                return MessageWindowIcon_Hand;
            case LogLevel_Error:
                return MessageWindowIcon_Error;
            case LogLevel_Warning:
                return MessageWindowIcon_Warning;
            case LogLevel_Info:
                return MessageWindowIcon_Information;
        }

        return MessageWindowIcon_Error;
    }

    MessageWindowLogger::MessageWindowLogger()
    {
        m_messageBox.buttons = MessageWindowButtons_Ok;
        m_messageBox.defaultButton = MessageWindowDefaultButton_Button1;
    }

    void MessageWindowLogger::write(const std::string& entry)
    {
        m_messageBox.open(entry, m_title);
    }

    std::string MessageWindowLogger::formatEntry(const std::string& entry, LogLevel level, const DateTime& date)
    {
        BULL_UNUSED(date);

        m_title = logLevelToString(level);
        m_messageBox.icon = chooseIcon(level);

        return entry;
    }
}