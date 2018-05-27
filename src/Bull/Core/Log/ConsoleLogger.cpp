#include <Bull/Core/Log/ConsoleLogger.hpp>

namespace Bull
{
    ConsoleLogger::ConsoleLogger()
    {
        m_output.setTextColor(ConsoleColor_Gray);
        m_output.setBackgroundColor(ConsoleColor_Black);

        m_levelTextColor[LogLevel_Error]   = ConsoleColor_Red;
        m_levelTextColor[LogLevel_Info]    = ConsoleColor_Cyan;
        m_levelTextColor[LogLevel_Debug]   = ConsoleColor_Gray;
        m_levelTextColor[LogLevel_Warning] = ConsoleColor_Yellow;

        m_levelBackgroundColor[LogLevel_Error]   = ConsoleColor_Black;
        m_levelBackgroundColor[LogLevel_Info]    = ConsoleColor_Black;
        m_levelBackgroundColor[LogLevel_Debug]   = ConsoleColor_Black;
        m_levelBackgroundColor[LogLevel_Warning] = ConsoleColor_Black;
    }

    void ConsoleLogger::setLevelTextColor(LogLevel level, ConsoleColor color)
    {
        m_levelTextColor[level] = color;
    }

    void ConsoleLogger::setLevelBackgroundColor(LogLevel level, ConsoleColor color)
    {
        m_levelBackgroundColor[level] = color;
    }

    void ConsoleLogger::write(const String& entry)
    {
        m_output.writeLine(entry);
    }

    String ConsoleLogger::formatEntry(const String& entry, LogLevel level, const DateTime& date)
    {
        m_output.setTextColor(m_levelTextColor[level]);
        m_output.setBackgroundColor(m_levelBackgroundColor[level]);

        return AbstractLogger::formatEntry(entry, level, date);
    }
}
