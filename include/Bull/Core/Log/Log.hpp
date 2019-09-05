#ifndef BULL_CORE_LOG_LOG_HPP
#define BULL_CORE_LOG_LOG_HPP

#include <memory>
#include <string>
#include <vector>

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Pattern/SharedSingleton.hpp>

namespace Bull
{
    class BULL_CORE_API Log : public SharedSingleton<Log>
    {
    public:

        /** \brief Write a message in the Log with a debug level
         *
         * \param message The message to write
         *
         */
        void debug(const std::string& message);

        /** \brief Write a message in the Log with a info level
         *
         * \param message The message to write
         *
         */
        void info(const std::string& message);

        /** \brief Write a message in the Log with a v level
         *
         * \param message The message to write
         *
         */
        void warning(const std::string& message);

        /** \brief Write a message in the Log with a error level
         *
         * \param message The message to write
         *
         */
        void error(const std::string& message);

        /** \brief Create a new AbstractLogger
         *
         * \param args Arguments to use to create the AbstractLogger
         *
         * \return The created AbstractLogger
         *
         */
        template <typename T, typename... Args>
        T& createLogger(Args&& ... args)
        {
            return static_cast<T&>(addLogger(std::make_unique<T>(std::forward<Args>(args)...)));
        }

        /** \brief Add an AbstractLogger
         *
         * \param logger The AbstractLogger to add
         *
         * \return The newly added AbstractLogger
         *
         */
        AbstractLogger& addLogger(std::unique_ptr<AbstractLogger>&& logger);

    private:

        friend class SharedSingleton<Log>;

        /** \brief Default constructor
         *
         */
        Log() = default;

    private:

        /** \brief Add an entry in every listener
         *
         * \param message The message to log
         * \param level   The message error level
         *
         */
        void write(const std::string& message, LogLevel level);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#endif // BULL_CORE_LOG_LOG_HPP
