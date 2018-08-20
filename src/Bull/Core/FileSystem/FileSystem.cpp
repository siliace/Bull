#include <Bull/Core/FileSystem/FileSystem.hpp>
#include <Bull/Core/FileSystem/FileSystemImpl.hpp>

namespace Bull
{
    Path FileSystem::getRoot()
    {
        return prv::FileSystemImpl::getRoot();
    }

    Path FileSystem::getHome()
    {
        return prv::FileSystemImpl::getHome();
    }

    Path FileSystem::getTempPath()
    {
        return prv::FileSystemImpl::getTempPath();
    }

    void FileSystem::setCurrentDirectory(const Path& path)
    {
        prv::FileSystemImpl::setCurrentDirectory(path);
    }

    Path FileSystem::getCurrentDirectory()
    {
        return Path(".").toAbsolute();
    }

    FileSystemInfo FileSystem::getFileSystemInfo(const Path& base)
    {
        return prv::FileSystemImpl::getFileSystemInfo(base);
    }

    void FileSystem::createLink(const Path& target, const String& link)
    {
        prv::FileSystemImpl::createLink(target, link);
    }
}