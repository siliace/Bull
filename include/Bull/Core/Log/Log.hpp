#ifndef Bull_Log_hpp
#define Bull_Log_hpp

#include <memory>
#include <vector>

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    class Log : public Singleton<Log>
    {
    public:

        enum Level
        {
            Debug,
            Info,
            Notice,
            Warning,
            Error,
            Critical,
            Alert,
            Emergency,
        };

        typedef std::unique_ptr<AbstractLogger>& AbstractLoggerHandler;

    public:

        /*! \brief Create a logger
         *
         * \param args Arguments to use to create the logger
         *
         * \return Return a pointer to the created logger
         *
         */
        template<typename T, typename... Args>
        AbstractLoggerHandler createLogger(Args... args);

        /*! \brief Add an entry in every listener
         *
         * \param message The message to log
         * \param level   The message error level
         *
         */
        virtual void write(const String& message, Level level);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#include <Bull/Core/Log/Log.inl>

#endif // Bull_Log_hpp
