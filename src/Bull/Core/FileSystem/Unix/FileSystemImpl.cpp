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
            return Path("/");
        }

        Path FileSystemImpl::getHome()
        {
            return Path("~").toAbsolute();
        }

        Path FileSystemImpl::getTempPath()
        {
            return getRoot().resolve("tmp");
        }

        void FileSystemImpl::setCurrentDirectory(const Path& path)
        {
            Expect(chdir(path.toString().c_str()) != -1, Throw(InternalError, "Failed to set current directory"));
        }

        FileSystemInfo FileSystemImpl::getFileSystemInfo(const Path& base)
        {
            FileSystemInfo info;
            struct statvfs64 stats;

            statvfs64(base.toString().c_str(), &stats);

            info.free = stats.f_bfree * stats.f_bsize;
            info.capacity = stats.f_blocks * stats.f_bsize;
            info.available = stats.f_bavail * stats.f_bsize;

            return info;
        }

        void FileSystemImpl::createLink(const Path& target, const std::string& link)
        {
            Expect(symlink(target.toString().c_str(), link.getBuffer()) != -1, Throw(InternalError, "Failed to create link"));
        }
    }
}
