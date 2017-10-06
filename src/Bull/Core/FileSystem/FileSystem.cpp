#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileSystem.hpp>
#include <Bull/Core/FileSystem/FileSystemImpl.hpp>

namespace Bull
{
    Path FileSystem::getRoot()
    {
        return prv::FileSystemImpl::getRoot();
    }

    Path FileSystem::getTempPath()
    {
        return prv::FileSystemImpl::getTempPath();
    }

    bool FileSystem::setCurrentDirectory(const Path& path)
    {
        return prv::FileSystemImpl::setCurrentDirectory(path);
    }

    Path FileSystem::getCurrentDirectory()
    {
        return Path::canonical(".");
    }

    FileSystemInfo FileSystem::getFileSystemInfo(const Path& base)
    {
        return prv::FileSystemImpl::getFileSystemInfo(base);
    }

    bool FileSystem::createLink(const Path& target, const String& link, bool force)
    {
        if((File::exists(link) || Directory::exists(link)) && force)
        {
            if(!File::remove(Path(link)) && !Directory::remove(Path(link)))
            {
                return false;
            }
        }

        return prv::FileSystemImpl::createLink(target, link);
    }
}