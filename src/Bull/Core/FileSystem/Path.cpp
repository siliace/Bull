#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>

namespace Bull
{
    Path Path::None = Path();

    bool Path::exists(const String& path)
    {
        return File::exists(path) || Directory::exists(path);
    }

    Path::Path() :
        m_isFile(false),
        m_isDirectory(false)
    {
        /// Nothing
    }

    Path::Path(const String& path)
    {
        set(path);
    }

    Path& Path::operator=(const String& path)
    {
        return set(path);
    }

    Path& Path::set(const String& path)
    {
        m_path        = path;
        m_isFile      = File::exists(path);
        m_isDirectory = Directory::exists(path);

        return (*this);
    }

    bool Path::operator==(const Path& right) const
    {
        return m_path == right.getPathName();
    }

    bool Path::operator!=(const Path& right) const
    {
        return !((*this) == right);
    }

    const String& Path::getPathName() const
    {
        return m_path;
    }

    bool Path::isFile() const
    {
        return m_isFile;
    }

    bool Path::isDirectory() const
    {
        return m_isDirectory;
    }

    bool Path::isValid() const
    {
        return m_isFile || m_isDirectory;
    }

    Path::operator String() const
    {
        return m_path;
    }

    Path::operator const char*() const
    {
        return static_cast<const char*>(m_path);
    }

    Path::operator bool() const
    {
        return isValid();
    }
}
