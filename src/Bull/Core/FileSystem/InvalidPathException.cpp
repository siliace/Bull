#include <Bull/Core/FileSystem/InvalidPathException.hpp>
#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    InvalidPathException::InvalidPathException(const String& path) :
        m_path(path)
    {
        /// Nothing
    }

    const String& InvalidPathException::getPath() const
    {
        return m_path;
    }

    String InvalidPathException::getLogMessage() const
    {
        StringStream ss;

        ss << "The path " << getPath() << " does not exists";

        return ss.toString();
    }
}