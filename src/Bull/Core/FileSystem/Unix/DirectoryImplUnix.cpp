#include <unistd.h>
#include <sys/stat.h>

#include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>
#include <Bull/Core/FileSystem/DirectorySearchFlag.hpp>

namespace Bull
{
    namespace prv
    {
        void DirectoryImplUnix::create(const Path& path)
        {
            mkdir(path.toString().c_str(), S_IRWXU | S_IRGRP | S_IROTH);
        }

        bool DirectoryImplUnix::exists(const Path& path)
        {
            struct stat64 filestats;

            if(stat64(path.toString().c_str(), &filestats) == -1)
            {
                return false;
            }

            return S_ISDIR(filestats.st_mode);
        }

        void DirectoryImplUnix::remove(const Path& path)
        {
            rmdir(path.toString().c_str());
        }

        DirectoryImplUnix::DirectoryImplUnix(const Path& path) :
                m_path(path)
        {
            m_handle = opendir(path.toString().c_str());
        }

        DirectoryImplUnix::~DirectoryImplUnix()
        {
            if(m_handle)
            {
                closedir(m_handle);
            }
        }

        std::vector<Path> DirectoryImplUnix::getContent(Uint32 flags)
        {
            dirent64* result;
            std::vector<Path> content;

            while((result = readdir64(m_handle)))
            {
                Path p = Path(m_path.toString() + Path::Separator + result->d_name);

                if((flags & (DirectorySearchFlag_Directories) && p.isDirectory()) || (flags & (DirectorySearchFlag_Files) && p.isFile()))
                {
                    content.push_back(p);
                }
            }

            return content;
        }
    }
}
