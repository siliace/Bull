#include <iostream>

#include <Bull/Core/Exception.hpp>
#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param message The message of the exception
     * \param level The log error level
     *
     */
    Exception::Exception(const String& message, Log::Level level) :
        m_message(message),
        m_level(level)
    {
        m_when = Date::now();
    }

    /*! \brief Save the exception into the log
     *
     */
    void Exception::log()
    {
        StringStream entry;

        entry << "Exception: " << "\n";
        entry << "Type: "      << getName()                   << "\n";
        entry << "File: "      << m_file                      << "\n";
        entry << "Function: "  << m_function                  << "\n";
        entry << "Line: "      << String::number(m_line)      << "\n";
        entry << "Date: "      << String::number(m_when.year) << "/" << String::number(m_when.month)  << "/" << String::number(m_when.day)                << "\n";
        entry << "At: "        << String::number(m_when.hour) << ":" << String::number(m_when.minute) << ":" << String::number(m_when.second.asSeconds()) << "\n";

        Log::get()->directWrite(entry);
    }
}
