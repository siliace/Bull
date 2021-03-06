#include <Bull/Core/FileSystem/Win32/FileSystemImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        Path FileSystemImpl::getRoot()
        {
            char buffer[255] = {0};
            GetEnvironmentVariable("systemdrive", buffer, 255);

            return Path(buffer);
        }

        Path FileSystemImpl::getHome()
        {
            char buffer[255] = {0};
            GetEnvironmentVariable("homepath", buffer, 255);

            return getRoot().resolve(buffer);
        }

        Path FileSystemImpl::getTempPath()
        {
            return getHome().resolve("AppData").resolve("Local").resolve("Temp");
        }

        bool FileSystemImpl::setCurrentDirectory(const Path& path)
        {
            return SetCurrentDirectory(path.toString().c_str()) == TRUE;
        }

        FileSystemInfo FileSystemImpl::getFileSystemInfo(const Path& base)
        {
            ULARGE_INTEGER free, total, totalFree;
            FileSystemInfo fileSystemInfo = {0, 0, 0};

            if(GetDiskFreeSpaceEx(base.toString().c_str(), &free, &total, &totalFree))
            {
                fileSystemInfo.free = totalFree.QuadPart;
                fileSystemInfo.available = free.QuadPart;
                fileSystemInfo.capacity = total.QuadPart;
            }

            return fileSystemInfo;
        }

        bool FileSystemImpl::createLink(const Path& target, const std::string& link)
        {
            return CreateSymbolicLink(link.c_str(), target.toString().c_str(), target.isDirectory() ? SYMBOLIC_LINK_FLAG_DIRECTORY : 0) != 0;
        }
    }
}
