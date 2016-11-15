#include <Bull/Utility/Log.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     */
    Log::Log() :
        m_fileName("BullApp.log")
    {
        m_log.open(m_fileName, File::OpeningMode::Write);
    }

    /*! \brief Destructor
     *
     */
    Log::~Log()
    {
        m_log.close();
    }

    /*! \brief Add a info entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::info(const String& message)
    {
        m_log.write("[Information] " + message + "\n");
    }

    /*! \brief Add a notice entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::notice(const String& message)
    {
        m_log.write("[Notice] " + message + "\n");
    }

    /*! \brief Add a warning entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::warning(const String& message)
    {
        m_log.write("[Warning] " + message + "\n");
    }

    /*! \brief Add an error entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::error(const String& message)
    {
        m_log.write("[Error] " + message + "\n");
    }

    /*! \brief Add a critical entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::critical(const String& message)
    {
        m_log.write("[Critical] " + message + "\n");
    }

    /*! \brief Add an alert entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::alert(const String& message)
    {
        m_log.write("[Alert] " + message + "\n");
    }

    /*! \brief Add an emergency entry in the log
     *
     * \param message The message to add in the log
     *
     */
    void Log::emergency(const String& message)
    {
        m_log.write("[Emergency] " + message + "\n");
    }

    /*! \brief Add a new entry in the log
     *
     * \param message The message to add in the log
     * \param level The level of the message
     *
     */
    void Log::log(const String& message, Log::Level level)
    {
        switch(level)
        {
            case Level::Info:      info(message); break;
            case Level::Notice:    notice(message); break;
            case Level::Warning:   warning(message); break;
            case Level::Error:     error(message); break;
            case Level::Critical:  critical(message); break;
            case Level::Alert:     alert(message); break;
            case Level::Emergency: emergency(message); break;
        }
    }

    /*! \brief Constructor
     *
     * \param fileName The name of the log file
     *
     */
    Log::Log(const String& fileName) :
        m_fileName(fileName)
    {
        m_log.open(m_fileName, File::OpeningMode::Write);
    }
}
