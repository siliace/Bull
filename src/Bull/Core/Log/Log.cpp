#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    void Log::write(const String& message, LogLevel level)
    {
        for(AbstractLoggerHandler& logger : m_listeners)
        {
            logger->write(message, level);
        }
    }
}
