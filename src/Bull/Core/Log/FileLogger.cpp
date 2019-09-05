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
            StreamLogger(m_file),
            m_file(path, FileOpeningMode_Truncate | FileOpeningMode_Write)
    {
        /// Nothing
    }
}