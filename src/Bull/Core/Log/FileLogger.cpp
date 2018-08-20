#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>
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
        m_file(path.toFile(FileOpeningMode_Truncate | FileOpeningMode_Write))
    {
        /// Nothing
    }

    void FileLogger::write(const String& entry)
    {
        TextWriter(m_file).writeLine(entry);
    }
}