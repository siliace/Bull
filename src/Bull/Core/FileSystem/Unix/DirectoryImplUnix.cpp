#include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplUnix::open(const String& path)
        {
            return false;
        }

        std::vector<Path> DirectoryImplUnix::getContent(Uint32 flags)
        {
            return std::vector<Path>();
        }
    }
}
