#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/PathImpl.hpp>

namespace Bull
{
    void Path::copy(const Path& path, const Path& newPath, bool failIfExists)
    {
        prv::PathImpl::copy(path, newPath, failIfExists);
    }

    void Path::rename(const Path& path, const Path& newPath)
    {
        prv::PathImpl::rename(path, newPath);
    }

    Path::Path(const std::string& path) :
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
        std::size_t end = m_path.find_last_of(Separator);

        if(end == std::string::npos)
        {
            return Path(m_path);
        }

        return Path(m_path.substr(0, end));
    }

    Path Path::resolve(const std::string& child) const
    {
        if(child.at(0) == Separator)
        {
            return Path(toString() + child);
        }

        return Path(toString() + Separator + child);
    }

    std::string Path::getFileName() const
    {
        std::size_t start = m_path.find_last_of(Separator);

        if(start == std::string::npos)
        {
            return m_path;
        }

        return m_path.substr(start + 1);
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

    const std::string& Path::toString() const
    {
        return m_path;
    }
}