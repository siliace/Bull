#ifndef BULL_CORE_LOG_CONSOLELOGGER_HPP
#define BULL_CORE_LOG_CONSOLELOGGER_HPP

#include <map>

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/System/ConsoleOutput.hpp>

namespace Bull
{
    class BULL_CORE_API ConsoleLogger : public AbstractLogger
    {
    public:

        /*! \brief Constructor
         *
         */
        ConsoleLogger();

        /*! \brief
         *
         * \param level
         * \param color
         *
         */
        void setLevelTextColor(LogLevel level, ConsoleColor color);

        /*! \brief
         *
         * \param level
         * \param color
         *
         */
        void setLevelBackgroundColor(LogLevel level, ConsoleColor color);

    protected:

        /*! \brief Write an entry in the StreamLogger
         *
         * \param entry The entry to write
         *
         */
        void write(const String& entry) override;

        /*! \brief
         *
         * \param level
         * \param date
         *
         */
        void prepareWrite(LogLevel level, const Date& date) override;

        /*! \brief Format a log entry
         *
         * \param entry The log entry to format
         * \param level The LogLevel to format
         * \param date  The date to when the entry should be written
         *
         * \return The formatted entry
         *
         */
        String formatEntry(const String& entry, LogLevel level, const Date& date) override;

    private:

        using ColorMap = std::map<LogLevel, ConsoleColor>;

        ConsoleOutput m_output;
        ColorMap      m_levelTextColor;
        ColorMap      m_levelBackgroundColor;
    };
}

#endif // BULL_CORE_LOG_CONSOLELOGGER_HPP
