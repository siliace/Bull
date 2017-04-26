#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    void Log::write(const String& message, Level level)
    {
        StringStream entry;
        Date now = Date::now();

        static String levelStrings[] =
        {
            "Debug",
            "Info",
            "Warning",
            "Error"
        };

        entry << "[" << String::number(now.year) << "/";
        entry << String::number(static_cast<unsigned int>(now.month))  << "/";
        entry << String::number(static_cast<unsigned int>(now.day));
        entry << " ";
        entry << String::number(now.hour) << ":" << String::number(now.minute) << ":" << String::number(now.second.asSeconds()) << "]";
        entry << "[" << levelStrings[level] << "]";
        entry << " : ";
        entry << message;

        for(AbstractLoggerHandler& logger : m_listeners)
        {
            logger->write(entry.toString());
        }
    }
}
