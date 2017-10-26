#include <Bull/Core/Log/Log.hpp>
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

    void MessageWindowLogger::write(const String& message, LogLevel level)
    {
        m_messageWindow.icon = chooseIcon(level);
        m_messageWindow.open(message, Log::getLevelString(level));
    }
}