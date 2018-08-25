#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/Log/FileLogger.hpp>

namespace Bull
{
    FileLogger::FileLogger() :
        FileLogger(Path("bull.log"))
    {
        /// Nothing
    }

    FileLogger::FileLogger(const Path& path) :
        m_file(path, FileOpeningMode_Truncate | FileOpeningMode_Write),
        m_writer(m_file)
    {
        /// Nothing
    }

    void FileLogger::write(const String& entry)
    {
        m_writer.writeLine(entry);
    }
}