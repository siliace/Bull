#ifndef BULL_CORE_LOG_ABSTRACTLOGGER_HPP
#define BULL_CORE_LOG_ABSTRACTLOGGER_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class Log;

    struct AbstractLogger
    {
    protected:

        friend class Log;

        /*! \brief Add a new entry in the log
         *
         * \param message The entry to add in the log
         *
         */
        virtual void write(const String& entry) = 0;
    };
}

#endif // BULL_CORE_LOG_ABSTRACTLOGGER_HPP
