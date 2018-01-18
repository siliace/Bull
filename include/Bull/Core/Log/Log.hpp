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

        /*! \brief Add a new logger
         *
         * \param logger The logger to add
         *
         */
        void addLogger(AbstractLogger* logger);

    private:

        std::vector<std::unique_ptr<AbstractLogger>> m_listeners;
    };
}

#endif // BULL_CORE_LOG_LOG_HPP
