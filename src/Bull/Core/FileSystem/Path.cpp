#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/InvalidPathException.hpp>
#include <Bull/Core/FileSystem/PathImpl.hpp>

namespace Bull
{
    Path Path::canonical(const String& path)
    {
        return Path(prv::PathImpl::realPath(path));
    }

    Path Path::canonical(const Path& path)
    {
        return canonical(path.toString());
    }

    Path::Path(const String& path)
    {
        open(path);
    }

    Path& Path::open(const String& path)
    {
        if(!File::exists(path) && !Directory::exists(path))
        {
            throw InvalidPathException(path);
        }

        m_path = path;

        return (*this);
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
        return Path(toString().subString(0, static_cast<std::size_t>(toString().last(Separator))).subString(static_cast<std::size_t>(toString().first(Separator))));
    }

    Path Path::getChild(const String& child) const
    {
        return Path(toString() + Separator + child);
    }

    String Path::getFileExtension() const
    {
        String path = toString();
        int i       = path.last('.');

        if(i != -1)
        {
            return path.subString(static_cast<std::size_t>(i) + 1);
        }

        return String();
    }

    bool Path::isFile() const
    {
        return File::exists(toString());
    }

    bool Path::isDirectory() const
    {
        return Directory::exists(toString());
    }

    const String& Path::toString() const
    {
        return m_path;
    }
}