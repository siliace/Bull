#ifndef BULL_ABSTRACTLOGGER_HPP
#define BULL_ABSTRACTLOGGER_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class Log;

    struct AbstractLogger
    {
        friend class Log;

    protected:

        /*! \brief Add a new entry in the log
         *
         * \param message The entry to add in the log
         *
         */
        virtual void write(const String& entry) = 0;
    };
}

#endif // BULL_ABSTRACTLOGGER_HPP
