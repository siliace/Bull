#ifndef BULL_CORE_LOG_LOG_HPP
#define BULL_CORE_LOG_LOG_HPP

#include <memory>
#include <vector>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    class BULL_CORE_API Log : public Singleton<Log>
    {
    public:

        typedef std::unique_ptr<AbstractLogger>& AbstractLoggerHandler;

        /*! \brief Get a LogLevel as a String
         *
         * \param level The LogLevel
         *
         * \return The String
         *
         */
        static String getLevelString(LogLevel level);

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
        void write(const String& message, LogLevel level);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#include <Bull/Core/Log/Log.inl>

#endif // BULL_CORE_LOG_LOG_HPP
