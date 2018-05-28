#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    String AbstractLogger::logLevelToString(LogLevel level)
    {
        switch(level)
        {
            case LogLevel_Debug:   return "Debug";
            case LogLevel_Info:    return "Info";
            case LogLevel_Warning: return "Warning";
            case LogLevel_Error:   return "Error";
        }
    }

    void AbstractLogger::setMinimalSeverity(LogLevel level)
    {
        m_minimalLevel = level;
    }

    LogLevel AbstractLogger::getMinimalSeverity() const
    {
        return m_minimalLevel;
    }

    void AbstractLogger::addEntry(const String& entry, LogLevel level, const DateTime& date)
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

    String AbstractLogger::formatEntry(const String& entry, LogLevel level, const DateTime& date)
    {
        OutStringStream oss;

        oss << "[" << StringUtils::number(date.getDate().getYear()) << "/" << StringUtils::number(date.getDate().getMonth()) <<  "/" << StringUtils::number(date.getDate().getDay());
        oss << " " << StringUtils::number(date.getTime().getHour()) << ":" << StringUtils::number(date.getTime().getMinute()) << ":" << StringUtils::number(date.getTime().getSecond());
        oss << "]";
        oss << "(" << logLevelToString(level) << ")";
        oss << " " << entry;

        return oss.toString();
    }
}