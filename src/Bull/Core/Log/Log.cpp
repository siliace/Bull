#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    void Log::write(const String& message, LogLevel level)
    {
        for(std::unique_ptr<AbstractLogger>& logger : m_listeners)
        {
            logger->addEntry(message, level);
        }
    }

    AbstractLogger& Log::addLogger(std::unique_ptr<AbstractLogger>&& logger)
    {
        m_listeners.emplace_back(std::move(logger));

        return (*m_listeners.back());
    }
}
