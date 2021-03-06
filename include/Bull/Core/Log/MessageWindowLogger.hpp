#ifndef BULL_CORE_LOG_WINDOWMESSAGELOGGER_HPP
#define BULL_CORE_LOG_WINDOWMESSAGELOGGER_HPP

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Window/MessageWindow.hpp>

namespace Bull
{
    class BULL_CORE_API MessageWindowLogger : public AbstractLogger
    {
    private:

        /** \brief Get the MessageWindowIcon according to a LogLevel
         *
         * \param level The LogLevel
         *
         * \return The MessageWindowIcon
         *
         */
        static MessageWindowIcon chooseIcon(LogLevel level);

    public:

        /** \brief Constructor
         *
         */
        MessageWindowLogger();

    protected:

        /** \brief Write an entry in the logger
         *
         * \param entry The entry to write
         *
         */
        void write(const std::string& entry) override;

        /** \brief Format a log entry
         *
         * \param entry The log entry to format
         * \param level The LogLevel to format
         * \param date  The date to when the entry should be written
         *
         * \return The formatted entry
         *
         */
        std::string formatEntry(const std::string& entry, LogLevel level, const DateTime& date) override;

    private:

        std::string m_title;
        MessageWindow m_messageBox;
    };
}

#endif // BULL_CORE_LOG_WINDOWMESSAGELOGGER_HPP
