#ifndef Bull_ConsoleLogger_hpp
#define Bull_ConsoleLogger_hpp

#include <Bull/Core/AbstractLogger.hpp>

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

#endif // Bull_ConsoleLogger_hpp