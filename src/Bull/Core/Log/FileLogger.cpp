#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Log/FileLogger.hpp>

namespace Bull
{
    FileLogger::FileLogger() :
        FileLogger("BullApp.log")
    {
        /// Nothing
    }

    FileLogger::FileLogger(const String& filename)
    {
        if(!File::exists(filename))
        {
            File::create(filename);
        }

        m_logFile.open(Path(filename), File::Truncate | File::Write);
    }

    void FileLogger::write(const String& entry, LogLevel level)
    {
        m_logFile.write(parseMessage(entry, level));
    }
}
