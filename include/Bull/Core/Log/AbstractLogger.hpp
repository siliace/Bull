#ifndef BULL_CORE_LOG_ABSTRACTLOGGER_HPP
#define BULL_CORE_LOG_ABSTRACTLOGGER_HPP

#include <Bull/Core/Log/LogLevel.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API AbstractLogger
    {
    protected:

        /*! \brief Convert the log message and the alert level to a log entry
         *
         * \param message The log message
         * \param level   The error level of the message
         *
         * \return The log entry
         *
         */
        String parseMessage(const String& message, LogLevel level) const;

    protected:

        friend class Log;

        /*! \brief Add a new entry in the log
         *
         * \param message The log message
         * \param level   The error level of the message
         *
         */
        virtual void write(const String& message, LogLevel level) = 0;
    };
}

#endif // BULL_CORE_LOG_ABSTRACTLOGGER_HPP
