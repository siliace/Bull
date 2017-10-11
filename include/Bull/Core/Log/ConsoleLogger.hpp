#ifndef BULL_CORE_LOG_CONSOLELOGGER_HPP
#define BULL_CORE_LOG_CONSOLELOGGER_HPP

#include <Bull/Core/Log/AbstractLogger.hpp>

namespace Bull
{
    class ConsoleLogger : public AbstractLogger
    {
    protected:

        /*! \brief Add a new entry in the log
         *
         * \param message The entry to add in the log
         *
         */
        void write(const String& entry) override;
    };
}

#endif // BULL_CORE_LOG_CONSOLELOGGER_HPP