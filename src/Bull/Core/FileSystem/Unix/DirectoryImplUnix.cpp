#include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplUnix::open(const String& path)
        {
            return false;
        }

        std::vector<FileSystemEntity> DirectoryImplUnix::getContent(Uint32 flags)
        {
            return std::vector<FileSystemEntity>();
        }

        DirectoryHandler DirectoryImplUnix::getSystemHandler() const
        {
            return nullptr;
        }
    }
}
