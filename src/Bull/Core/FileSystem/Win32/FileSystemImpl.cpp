#include <Bull/Core/FileSystem/Win32/FileSystemImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        Path FileSystemImpl::getRoot()
        {
            String root(static_cast<Index>(255));

            GetEnvironmentVariable("systemdrive", &root[0], static_cast<DWORD>(root.getCapacity()));

            return Path(root);
        }

        Path FileSystemImpl::getHome()
        {
            String userPath(static_cast<Index>(255));

            GetEnvironmentVariable("homepath", &userPath[0], static_cast<DWORD>(userPath.getCapacity()));

            return getRoot().getChild(userPath);
        }

        Path FileSystemImpl::getTempPath()
        {
            return getHome().getChild("AppData").getChild("Local").getChild("Temp");
        }

        bool FileSystemImpl::setCurrentDirectory(const Path& path)
        {
            return SetCurrentDirectory(path.toString().getBuffer()) == TRUE;
        }

        FileSystemInfo FileSystemImpl::getFileSystemInfo(const Path& base)
        {

        }

        bool FileSystemImpl::createLink(const Path& target, const String& link)
        {

        }
    }
}
