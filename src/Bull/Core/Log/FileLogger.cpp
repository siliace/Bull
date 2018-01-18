#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/Log/FileLogger.hpp>

namespace Bull
{
    FileLogger::FileLogger()
    {
        String path = "bull.log";

        if(!File::exists(path))
        {
            if(!File::create(path))
            {
                throw RuntimeError("Failed to create bull.log file");
            }
        }

        if(!m_file.open(Path(path), FileOpeningMode_Truncate | FileOpeningMode_Write))
        {
            throw RuntimeError("Failed to open bull.log file");
        }
    }

    FileLogger::FileLogger(const Path& path)
    {
        if(!m_file.open(path, FileOpeningMode_Truncate | FileOpeningMode_Write))
        {
            throw RuntimeError("Failed to open bull.log file");
        }
    }

    void FileLogger::write(const String& entry)
    {
        m_file.write(entry);
    }
}