#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    Path::Path() :
        m_isFile(false),
        m_isDirectory(false)
    {
        /// Nothing
    }

    Path::Path(const String& path) :
        m_path(path)
    {
        m_isFile      = File::exists(m_path);
        m_isDirectory = Directory::exists(m_path);

        if(!m_isFile && !m_isDirectory)
        {
            StringStream ss;

            ss << "The path " << m_path << " does not exists";

            throw std::invalid_argument(ss.toString().getBuffer());
        }
    }

    bool Path::operator==(const Path& right) const
    {
        return m_path == right.toString();
    }

    bool Path::operator!=(const Path& right) const
    {
        return m_path != right.toString();
    }

    bool Path::isFile() const
    {
        return m_isFile;
    }

    bool Path::isDirectory() const
    {
        return m_isDirectory;
    }

    String Path::toString() const
    {
        return m_path;
    }
}
