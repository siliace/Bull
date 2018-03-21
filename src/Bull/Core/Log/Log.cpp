#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    void Log::debug(const String& message)
    {
        write(message, LogLevel_Debug);
    }

    void Log::info(const String& message)
    {
        write(message, LogLevel_Info);
    }

    void Log::warning(const String& message)
    {
        write(message, LogLevel_Warning);
    }

    void Log::error(const String& message)
    {
        write(message, LogLevel_Error);
    }

    AbstractLogger& Log::addLogger(std::unique_ptr<AbstractLogger>&& logger)
    {
        m_listeners.emplace_back(std::move(logger));

        return (*m_listeners.back());
    }

    void Log::write(const String& message, LogLevel level)
    {
        for(std::unique_ptr<AbstractLogger>& logger : m_listeners)
        {
            logger->addEntry(message, level);
        }
    }
}
