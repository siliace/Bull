#ifndef BULL_CORE_LOG_MESSAGEBOXLOGGER_HPP
#define BULL_CORE_LOG_MESSAGEBOXLOGGER_HPP

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Window/MessageWindow.hpp>

namespace Bull
{
    class BULL_CORE_API MessageWindowLogger : public AbstractLogger
    {
    public:

        /*! \brief Default constructor
         *
         */
        MessageWindowLogger() = default;

        /*! \brief Add a new entry in the log
         *
         * \param message The log message
         * \param level   The error level of the message
         *
         */
        void write(const String& message, LogLevel level) override;

    private:

        MessageWindow m_messageWindow;
    };
}

#endif // BULL_CORE_LOG_MESSAGEBOXLOGGER_HPP
