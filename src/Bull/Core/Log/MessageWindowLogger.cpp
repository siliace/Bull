#include <Bull/Core/Log/MessageWindowLogger.hpp>

namespace Bull
{
    void MessageWindowLogger::write(const String& message, LogLevel level)
    {
        static String levelStrings[] =
        {
            "Debug",
            "Info",
            "Warning",
            "Error"
        };

        switch(level)
        {
            case LogLevel_Debug:   m_messageWindow.icon = MessageWindowIcon_Hand; break;
            case LogLevel_Error:   m_messageWindow.icon = MessageWindowIcon_Error; break;
            case LogLevel_Warning: m_messageWindow.icon = MessageWindowIcon_Warning; break;
            case LogLevel_Info:    m_messageWindow.icon = MessageWindowIcon_Information; break;
        }

        m_messageWindow.open(message, levelStrings[level]);
    }
}