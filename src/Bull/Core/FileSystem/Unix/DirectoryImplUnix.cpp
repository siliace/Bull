#include <unistd.h>
#include <sys/stat.h>

#include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplUnix::create(const String& path)
        {
            return mkdir(path.getBuffer(), S_IRWXU | S_IRGRP | S_IROTH) != -1;
        }

        bool DirectoryImplUnix::exists(const String& path)
        {
            struct stat64 filestats;

            if(stat64(path.getBuffer(), &filestats) == -1)
            {
                return false;
            }

            return S_ISDIR(filestats.st_mode);
        }

        bool DirectoryImplUnix::remove(const Path& path)
        {
            return rmdir(path.toString().getBuffer()) != -1;
        }

        DirectoryImplUnix::DirectoryImplUnix() :
            m_handler(nullptr)
        {
            /// Nothing
        }

        DirectoryImplUnix::~DirectoryImplUnix()
        {
            if(m_handler)
            {
                closedir(m_handler);
            }
        }

        bool DirectoryImplUnix::open(const Path& path)
        {
            m_handler = opendir(path.toString().getBuffer());

            if(!m_handler)
            {
                return false;
            }

            m_path = path;

            return true;
        }

        std::vector<Path> DirectoryImplUnix::getContent(Uint32 flags)
        {
            dirent64* result;
            std::vector<Path> content;

            while((result = readdir64(m_handler)))
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
