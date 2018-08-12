#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LackOfImplementation.hpp>
#include <Bull/Core/Exception/UnsupportedOperation.hpp>
#include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>
#include <Bull/Core/Support/Unix/DateHelper.hpp>

namespace Bull
{
    namespace prv
    {
        void FileImplUnix::create(const String& name)
        {
            int handler = ::open64(name.getBuffer(), O_CREAT | O_TRUNC | O_EXCL, S_IRWXU);

            Expect(handler != -1, Throw(InternalError, "FileImplUnix::create", "Failed to create file"));

            close(handler);
        }

        bool FileImplUnix::exists(const String& name)
        {
            struct stat64 filestats;

            Expect(stat64(name.getBuffer(), &filestats) != -1, Throw(InternalError, "FileImplUnix::exists", "Failed to check whether a file exists"))

            return S_ISREG(filestats.st_mode);
        }

        bool FileImplUnix::copy(const Path& path, const String& newPath)
        {
            Throw(LackOfImplementation, "FileImplUnix::copy", "Unimplemented method");
        }

        void FileImplUnix::remove(const Path& name)
        {
            Expect(unlink(name.toString().getBuffer()) != -1, Throw(InternalError, "FileImplUnix::remove", "Failed to remove file"));
        }

        FileImplUnix::~FileImplUnix()
        {
            close(m_handler);
        }

        bool FileImplUnix::open(const Path& name, Uint32 mode)
        {
            int flags = 0;

            if(mode & FileOpeningMode_ReadWrite)
            {
                flags |= O_RDWR;
            }
            else
            {
                if(mode & FileOpeningMode_Read)
                {
                    flags |= O_RDONLY;
                }
                else if(mode & FileOpeningMode_Write)
                {
                    flags |= O_WRONLY;
                }
            }

            if(!(mode & FileOpeningMode_Exists) && mode & FileOpeningMode_Write)
            {
                flags |= O_CREAT;
            }

            if(mode & FileOpeningMode_Truncate)
            {
                flags |= O_TRUNC;
            }

            m_handler = ::open64(name.toString().getBuffer(), flags, S_IRWXU);

            return m_handler != -1;
        }

        Uint64 FileImplUnix::read(void* dst, Uint64 size)
        {
            lockf64(m_handler, F_LOCK, size);
            Uint64 read = ::read(m_handler, dst, size);
            lockf64(m_handler, F_ULOCK, size);

            return read;
        }

        Uint64 FileImplUnix::write(const void* data, Uint64 size)
        {
            lockf64(m_handler, F_LOCK, size);
            Uint64 written = ::write(m_handler, data, size);
            lockf64(m_handler, F_ULOCK, size);

            return written;
        }

        void FileImplUnix::flush()
        {
            Expect(fsync(m_handler) != -1, Throw(InternalError, "FileImplUnix::flush", "Failed to sync file descriptor"));
        }

        DateTime FileImplUnix::getCreationDate() const
        {
            Throw(UnsupportedOperation, "FileImplUnix::getCreationDate", "Creation date is not supported on your system");
        }

        DateTime FileImplUnix::getLastAccessDate() const
        {
            struct stat64 info;

            fstat64(m_handler, &info);

            return systemTimeToDate(localtime(&info.st_atim.tv_sec));
        }

        DateTime FileImplUnix::getLastWriteDate() const
        {
            struct stat64 info;

            fstat64(m_handler, &info);

            return systemTimeToDate(localtime(&info.st_mtim.tv_sec));
        }

        Uint64 FileImplUnix::getCursor() const
        {
            return lseek64(m_handler, 0, SEEK_CUR);
        }

        Uint64 FileImplUnix::moveCursor(Int64 offset)
        {
            return lseek64(m_handler, offset, SEEK_CUR);
        }

        Uint64 FileImplUnix::setCursor(Uint64 offset)
        {
            return lseek64(m_handler, offset, SEEK_SET);
        }

        Uint64 FileImplUnix::getSize() const
        {
            struct stat64 info;
            fstat64(m_handler, &info);

            return static_cast<Uint64>(info.st_size);
        }
    }
}
