#include <Bull/Utility/FileLogger.hpp>

namespace Bull
{
    FileLogger::FileLogger() :
        FileLogger("BullApp.log")
    {
        /// Nothing
    }

    FileLogger::FileLogger(const String& filename) :
        m_logFile(filename, File::Truncate | File::Write)
    {
        /// Nothing
    }

    void FileLogger::write(const String& entry)
    {
        m_logFile.write(entry);
    }
}
