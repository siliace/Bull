#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    /*! \brief Add an entry in every listener
     *
     * \param message The message to log
     * \param level   The message error level
     *
     */
    void Log::write(const String& message, Level level)
    {
        StringStream entry;
        Date now = Date::now();

        entry << "[" << String::number(now.year) << "/" << String::number(now.month)  << "/" << String::number(now.day);
        entry << " ";
        entry << String::number(now.hour) << ":" << String::number(now.minute) << ":" << String::number(now.second.asSeconds()) << "]";
        entry << message;

        directWrite(entry);
    }

    /*! \brief Add an entry in every listener without formating
     *
     * \param message The message to log
     *
     */
    void Log::directWrite(const String& message)
    {
        for(AbstractLoggerHandler& logger : m_listeners)
        {
            logger->write(message);
        }
    }
}
