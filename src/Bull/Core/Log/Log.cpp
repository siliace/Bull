#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    String Log::getLevelString(LogLevel level)
    {
        switch(level)
        {
            case LogLevel_Debug:   return "Debug";
            case LogLevel_Info:    return "Info";
            case LogLevel_Warning: return "Warning";
            case LogLevel_Error:   return "Error";
        }
    }

    void Log::write(const String& message, LogLevel level)
    {
        for(AbstractLoggerHandler& logger : m_listeners)
        {
            logger->write(message, level);
        }
    }
}
