#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    void Log::debug(const std::string& message)
    {
        write(message, LogLevel_Debug);
    }

    void Log::info(const std::string& message)
    {
        write(message, LogLevel_Info);
    }

    void Log::warning(const std::string& message)
    {
        write(message, LogLevel_Warning);
    }

    void Log::error(const std::string& message)
    {
        write(message, LogLevel_Error);
    }

    AbstractLogger& Log::addLogger(std::unique_ptr<AbstractLogger>&& logger)
    {
        m_listeners.emplace_back(std::move(logger));

        return (*m_listeners.back());
    }

    void Log::write(const std::string& message, LogLevel level)
    {
        for(auto& logger : m_listeners)
        {
            logger->addEntry(message, level);
        }
    }
}
