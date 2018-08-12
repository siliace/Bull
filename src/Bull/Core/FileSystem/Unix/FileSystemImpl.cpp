#include <sys/statvfs.h>
#include <unistd.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/Unix/FileSystemImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Path FileSystemImpl::getRoot()
        {
            return Path::canonical("/");
        }

        Path FileSystemImpl::getHome()
        {
            return Path::canonical("~");
        }

        Path FileSystemImpl::getTempPath()
        {
            return getRoot().getChild("tmp");
        }

        void FileSystemImpl::setCurrentDirectory(const Path& path)
        {
            Expect(chdir(path.toString().getBuffer()) != -1, Throw(InternalError, "FileSystemImpl::setCurrentDirectory", "Failed to set current directory"));
        }

        FileSystemInfo FileSystemImpl::getFileSystemInfo(const Path& base)
        {
            FileSystemInfo   info;
            struct statvfs64 stats;

            statvfs64(base.toString().getBuffer(), &stats);

            info.free = stats.f_bfree * stats.f_bsize;
            info.capacity = stats.f_blocks * stats.f_bsize;
            info.available = stats.f_bavail * stats.f_bsize;

            return info;
        }

        void FileSystemImpl::createLink(const Path& target, const String& link)
        {
            Expect(symlink(target.toString().getBuffer(), link.getBuffer()) != -1, Throw(InternalError, "FileSystemImpl::createLink", "Failed to create link"));
        }
    }
}
