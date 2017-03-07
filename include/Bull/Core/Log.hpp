#ifndef Bull_Log_hpp
#define Bull_Log_hpp

#include <memory>
#include <vector>

#include <Bull/Core/AbstractLogger.hpp>
#include <Bull/Core/Log.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/String.hpp>

namespace Bull
{
    class Log : public Singleton<Log>
    {
    public:

        enum Level
        {
            Info,
            Notice,
            Warning,
            Error,
            Critical,
            Alert,
            Emergency
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

        /*! \brief Add an entry in every listener without formating
         *
         * \param message The message to log
         *
         */
        void directWrite(const String& message);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#include <Bull/Core/Log.inl>

#endif // Bull_Log_hpp
