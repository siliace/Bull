#ifndef BULL_CORE_LOG_ABSTRACTLOGGER_HPP
#define BULL_CORE_LOG_ABSTRACTLOGGER_HPP

#include <Bull/Core/Log/LogLevel.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    class Log;

    class BULL_CORE_API AbstractLogger
    {
    protected:

        /*! \brief Convert a LogLevel to its String equivalent
         *
         * \param level The LogLevel to convert
         *
         * \return The LogLevel as a String
         *
         */
        static String logLevelToString(LogLevel level);

    public:

        /*! \brief Set the minimal LogLevel required by a log entry to be written
         *
         * \param level The LogLevel
         *
         */
        void setMinimalSeverity(LogLevel level);

        /*! \brief Get the minimal LogLevel required by a log entry to be written
         *
         * \return The LogLevel
         *
         */
        LogLevel getMinimalSeverity() const;

    protected:

        friend class Log;

        /*! \brief Add a log entry in the logger
         *
         * \param message The entry
         * \param level   The LogLevel of the entry
         * \param date    The date when the entry should be added
         *
         */
        void addEntry(const String& entry, LogLevel level, const Date& date = Date::now());

    protected:

        /*! \brief Constructor
         *
         * \param minimalLevel The minimal LogLevel required by a log entry to be written
         *
         */
        explicit AbstractLogger(LogLevel minimalLevel = LogLevel_Info);

        /*! \brief Write an entry in the logger
         *
         * \param entry The entry to write
         *
         */
        virtual void write(const String& entry) = 0;

        /*! \brief Format a log entry
         *
         * \param entry The log entry to format
         * \param level The LogLevel to format
         * \param date  The date to when the entry should be written
         *
         * \return The formatted entry
         *
         */
        virtual String formatEntry(const String& entry, LogLevel level, const Date& date);

    private:

        /*! \brief Tell whether an entry should be written
         *
         * \param level The LogLevel of the entry
         *
         * \return True if the entry should be written
         *
         */
        bool shouldWriteEntry(LogLevel level) const;

        LogLevel m_minimalLevel;
    };
}

#endif // BULL_CORE_LOG_ABSTRACTLOGGER_HPP
