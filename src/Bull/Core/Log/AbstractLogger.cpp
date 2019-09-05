#include <sstream>

#include <Bull/Core/Log/AbstractLogger.hpp>

namespace Bull
{
    std::string AbstractLogger::logLevelToString(LogLevel level)
    {
        switch(level)
        {
            case LogLevel_Debug:
                return "Debug";
            case LogLevel_Info:
                return "Info";
            case LogLevel_Warning:
                return "Warning";
            case LogLevel_Error:
                return "Error";
        }

        return "";
    }

    void AbstractLogger::setMinimalSeverity(LogLevel level)
    {
        m_minimalLevel = level;
    }

    LogLevel AbstractLogger::getMinimalSeverity() const
    {
        return m_minimalLevel;
    }

    void AbstractLogger::addEntry(const std::string& entry, LogLevel level, const DateTime& date)
    {
        if(shouldWriteEntry(level))
        {
            write(formatEntry(entry, level, date));
        }
    }

    AbstractLogger::AbstractLogger(LogLevel minimalLevel) :
            m_minimalLevel(minimalLevel)
    {
        /// Nothing
    }

    bool AbstractLogger::shouldWriteEntry(LogLevel level) const
    {
        return level >= m_minimalLevel;
    }

    std::string AbstractLogger::formatEntry(const std::string& entry, LogLevel level, const DateTime& date)
    {
        std::ostringstream oss;

        oss << "[" << date.getDate().getYear() << "/" << date.getDate().getMonth() << "/" << date.getDate().getDay();
        oss << " " << date.getTime().getHour() << ":" << date.getTime().getMinute() << ":" << date.getTime().getSecond();
        oss << "]";
        oss << "(" << logLevelToString(level) << ")";
        oss << " " << entry;

        return oss.str();
    }
}