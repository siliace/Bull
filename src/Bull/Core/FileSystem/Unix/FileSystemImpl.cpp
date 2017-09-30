#include <sys/statvfs.h>
#include <unistd.h>

#include <Bull/Core/FileSystem/Unix/FileSystemImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Path FileSystemImpl::getRoot()
        {
            return Path::canonical("/");
        }

        Path FileSystemImpl::getTempPath()
        {
            return getRoot().getChild("tmp");
        }

        bool FileSystemImpl::setCurrentDirectory(const Path& path)
        {
            return chdir(path.toString().getBuffer()) != -1;
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

        bool FileSystemImpl::createLink(const Path& target, const String& link)
        {
            return symlink(target.toString().getBuffer(), link.getBuffer()) != -1;
        }
    }
}
