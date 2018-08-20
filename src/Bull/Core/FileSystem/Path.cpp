#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>
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
        return Path(toString().subString(0, toString().last(Separator)).subString(toString().first(Separator)));
    }

    Path Path::resolve(const String& child) const
    {
        return Path(toString() + Separator + child);
    }

    Path Path::toAbsolute() const
    {
        return Path(prv::PathImpl::realPath(m_path));
    }

    bool Path::isFile() const
    {
        return File::exists(toString());
    }

    File Path::toFile(Uint32 mode) const
    {
        return File(m_path, mode);
    }

    bool Path::isDirectory() const
    {
        return Directory::exists(toString());
    }

    Directory Path::toDirectory() const
    {
        return Directory(m_path);
    }

    const String& Path::toString() const
    {
        return m_path;
    }
}