#include <Bull/Core/Exception/FileNotFound.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
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
            Throw(FileNotFound, "Path::open", "The path " + path + " does not exists");
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
        return Path(toString().subString(0, toString().last(Separator)).subString(toString().first(Separator)));
    }

    Path Path::getChild(const String& child) const
    {
        return Path(toString() + Separator + child);
    }

    String Path::getFileExtension() const
    {
        String path = toString();
        std::size_t pos = path.last('.');

        if(pos < String::InvalidPosition)
        {
            return path.subString(pos + 1);
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