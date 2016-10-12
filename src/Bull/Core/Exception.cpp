#include <Bull/Core/Exception.hpp>

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
        /// Nothing
    }

    /*! \brief Save the exception into the log
     *
     */
    void Exception::log()
    {
        Log::get()->log("Exception " + getName() + " with message " + m_message + "\n", m_level);
    }
}
