#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    String AbstractLogger::parseMessage(const String& entry, LogLevel level) const
    {
        StringStream ss;
        Date now = Date::now();

        static String levelStrings[] =
        {
            "Debug",
            "Info",
            "Warning",
            "Error"
        };

        ss << "[" << String::number(now.year) << "/";
        ss << String::number(static_cast<unsigned int>(now.month))  << "/";
        ss << String::number(static_cast<unsigned int>(now.day));
        ss << " ";
        ss << String::number(now.hour) << ":" << String::number(now.minute) << ":" << String::number(now.second.asSeconds()) << "]";
        ss << "[" << levelStrings[level] << "]";
        ss << " : ";
        ss << entry;

        return ss.toString();
    }
}