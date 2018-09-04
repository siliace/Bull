#ifndef BULL_CORE_LOG_CONSOLELOGGER_HPP
#define BULL_CORE_LOG_CONSOLELOGGER_HPP

#include <map>

#include <Bull/Core/Log/StreamLogger.hpp>
#include <Bull/Core/System/ConsoleOutput.hpp>

namespace Bull
{
    class BULL_CORE_API ConsoleLogger : public StreamLogger
    {
    public:

        /*! \brief Constructor
         *
         */
        ConsoleLogger();

        /*! \brief Set the ConsoleColor to use to write a log entry according to its LogLevel
         *
         * \param level The LogLevel
         * \param color The ConsoleColor
         *
         */
        void setLevelTextColor(LogLevel level, ConsoleColor color);

        /*! \brief Set the background ConsoleColor a log entry according to its LogLevel
         *
         * \param level The LogLevel
         * \param color The ConsoleColor
         *
         */
        void setLevelBackgroundColor(LogLevel level, ConsoleColor color);

    protected:

        /*! \brief Format a log entry
         *
         * \param entry The log entry to format
         * \param level The LogLevel to format
         * \param date  The date to when the entry should be written
         *
         * \return The formatted entry
         *
         */
        String formatEntry(const String& entry, LogLevel level, const DateTime& date) override;

    private:

        using ColorMap = std::map<LogLevel, ConsoleColor>;

        ConsoleOutput m_output;
        ColorMap      m_levelTextColor;
        ColorMap      m_levelBackgroundColor;
    };
}

#endif // BULL_CORE_LOG_CONSOLELOGGER_HPP
