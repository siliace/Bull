#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>

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

    void AbstractLogger::addEntry(const String& entry, LogLevel level, const Date& date)
    {
        if(shouldWriteEntry(level))
        {
            prepareWrite(level, date);
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

    String AbstractLogger::formatEntry(const String& entry, LogLevel level, const Date& date)
    {
        OutStringStream oss;

        oss << "[" << String::number(date.year) << "/" << String::number(date.month) <<  "/" << String::number(date.day);
        oss << " " << String::number(date.hour) << ":" << String::number(date.minute) << ":" << String::number(date.second.asSeconds());
        oss << "]";
        oss << "(" << logLevelToString(level) << ")";
        oss << " " << entry;

        return oss.toString();
    }
}