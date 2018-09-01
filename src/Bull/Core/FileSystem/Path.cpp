#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/PathImpl.hpp>

namespace Bull
{
    Path::Path(const String& path) :
        m_path(path)
    {
        /// Nothing
    }

    bool Path::operator==(const Path& right) const
    {
        return toString() == right.toString();
    }

    bool Path::operator!=(const Path& right) const
    {
        return toString() != right.toString();
    }

    Path Path::getParent() const
    {
        std::size_t end = m_path.last(Separator);

        if(end == String::InvalidPosition)
        {
            return Path(m_path);
        }

        return Path(m_path.subString(0, end));
    }

    Path Path::resolve(const String& child) const
    {
        if(child.at(0) == Separator)
        {
            return Path(toString() + child);
        }

        return Path(toString() + Separator + child);
    }

    String Path::getFileName() const
    {
        std::size_t start = m_path.last(Separator);

        if(start == String::InvalidPosition)
        {
            return m_path;
        }

        return m_path.subString(start + 1);
    }

    Path Path::toAbsolute() const
    {
        return Path(prv::PathImpl::realPath(m_path));
    }

    bool Path::isFile() const
    {
        return File::exists(*this);
    }

    bool Path::isDirectory() const
    {
        return Directory::exists(*this);
    }

    const String& Path::toString() const
    {
        return m_path;
    }
}