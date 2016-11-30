#include <Bull/Utility/FileLogger.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    FileLogger::FileLogger() :
        FileLogger("BullApp.log")
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param filename The name of the log file
     *
     */
    FileLogger::FileLogger(const String& filename) :
        m_logFile(filename, File::Truncate | File::Write)
    {
        if(!m_logFile.isOpen())
        {
            ThrowException(FailToOpenLog);
        }
    }

    /*! \brief Add a new entry in the log
     *
     * \param message The entry to add in the log
     *
     */
    void FileLogger::write(const String& entry)
    {
        m_logFile.write(entry);
    }
}
