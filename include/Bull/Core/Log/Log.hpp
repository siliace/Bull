#ifndef BULL_CORE_LOG_LOG_HPP
#define BULL_CORE_LOG_LOG_HPP

#include <memory>
#include <vector>

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    class BULL_CORE_API Log : public Singleton<Log>
    {
    public:

        /*! \brief Add an entry in every listener
         *
         * \param message The message to log
         * \param level   The message error level
         *
         */
        void write(const String& message, LogLevel level);

        /*! \brief Create a new AbstractLogger
         *
         * \param args Arguments to use to create the AbstractLogger
         *
         * \return The created AbstractLogger
         *
         */
        template <typename T, typename... Args>
        T& createLogger(Args&&... args)
        {
            std::unique_ptr<AbstractLogger> logger(new T(std::forward<Args>(args)...));

            return static_cast<T&>(addLogger(std::move(logger)));
        }

        /*! \brief Add an AbstractLogger
         *
         * \param logger The AbstractLogger to add
         *
         * \return The newly added AbstractLogger
         *
         */
        AbstractLogger& addLogger(std::unique_ptr<AbstractLogger>&& logger);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#endif // BULL_CORE_LOG_LOG_HPP
