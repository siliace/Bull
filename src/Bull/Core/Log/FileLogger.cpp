#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Log/FileLogger.hpp>

namespace Bull
{
    FileLogger::FileLogger()
    {
        String path = "bull.log";

        if(!File::exists(path))
        {
            File::create(path);
        }

        if(!m_file.open(Path(path), FileOpeningMode_Truncate | FileOpeningMode_Write))
        {
            Throw(InternalError, "FileLogger::FileLogger", "Failed to open log file");
        }
    }

    FileLogger::FileLogger(const Path& path)
    {
        if(!m_file.open(path, FileOpeningMode_Truncate | FileOpeningMode_Write))
        {
            Throw(InternalError, "FileLogger::FileLogger", "Failed to open log file");
        }
    }

    void FileLogger::write(const String& entry)
    {
        m_file.writeLine(entry);
    }
}