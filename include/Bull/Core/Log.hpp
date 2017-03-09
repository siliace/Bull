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
            Debug     = 0x0,
            Info      = 0x1,
            Notice    = 0x2,
            Warning   = 0x4,
            Error     = 0x8,
            Critical  = 0x16,
            Alert     = 0x32,
            Emergency = 0x64,
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

#include <Bull/Core/Log.inl>

#endif // Bull_Log_hpp
