#include <unistd.h>
#include <sys/stat.h>

#include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplUnix::create(const String& path)
        {
            return mkdir(path, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) != -1;
        }

        bool DirectoryImplUnix::exists(const String& path)
        {
            struct stat64 filestats;

            if(stat64(path, &filestats) == -1)
            {
                return false;
            }

            return S_ISDIR(filestats.st_mode);
        }

        bool DirectoryImplUnix::remove(const Path& path)
        {
            return rmdir(path.toString()) != -1;
        }

        DirectoryImplUnix::~DirectoryImplUnix()
        {

        }

        bool DirectoryImplUnix::open(const Path& path)
        {

        }

        std::vector<Path> DirectoryImplUnix::getContent(Uint32 flags)
        {

        }
    }
}
