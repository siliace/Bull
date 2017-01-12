#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>
#include <Bull/Core/Log.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a file
         *
         * \param name The name of the file to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        bool FileImplUnix::create(const String& name)
        {
            int handler = ::open(name, O_CREAT | O_TRUNC | O_EXCL, S_IRWXU);

            if(handler == -1)
            {
                return false;
            }

            close(handler);

            return true;
        }

        /*! \brief Check if a file exists
         *
         * \param name The name of the file to check
         *
         * \return Return true if the file exists, false otherwise
         *
         */
        bool FileImplUnix::exists(const String& name)
        {
            return access(name, F_OK) != -1;
        }

        /*! \brief Copy a file
         *
         * \param path The path (relative or absolute) of the file to copy
         * \param path The new path (relative or absolute) of the file
         *
         * \return Return true if the copy was successfully, false otherwise
         *
         */
        bool FileImplUnix::copy(const String& path, const String& newPath)
        {
            return false;
        }

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         * \return Return true if the file was deleted successfully, false otherwise
         *
         */
        bool FileImplUnix::remove(const String& name)
        {
            return unlink(name) != -1;
        }

        /*! \brief Destructor
         *
         */
        FileImplUnix::~FileImplUnix()
        {
            close(m_handler);
        }

        /*! \brief Open a file
         *
         * \param name The name of the file
         * \param mode The opening mode of the file (read, write or both)
         *
         * \return Return true if the file was open successfully, false otherwise
         *
         */
        bool FileImplUnix::open(const String& name, Uint32 mode)
        {
            int flags = 0;

            if(mode & File::OpeningMode::ReadWrite)
            {
                flags |= O_RDWR;
            }
            else
            {
                if(mode & File::OpeningMode::Read)
                {
                    flags |= O_RDONLY;
                }
                else if(mode & File::OpeningMode::Write)
                {
                    flags |= O_WRONLY;
                }
            }

            if(!(mode & File::OpeningMode::Exists) && mode & File::OpeningMode::Write)
            {
                flags |= O_CREAT;
            }

            if(mode & File::OpeningMode::Truncate)
            {
                flags |= O_TRUNC;
            }

            m_handler = ::open64(name, flags, S_IRWXU);

            return m_handler != -1;
        }

        /*! \brief Read in a file
         *
         * \param dst The destination of the read data
         * \param size The number of byte to read
         *
         * \param Return the number of byte read
         *
         */
        Uint64 FileImplUnix::read(void* dst, Uint64 size)
        {
            return ::read(m_handler, dst, size);
        }

        /*! \brief Write a byte in this file
         *
         * \param byte A byte to write
         *
         */
        Uint64 FileImplUnix::write(const void* data, Uint64 size)
        {
            return ::write(m_handler, data, size);
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the creation of the file
         *
         */
        Date FileImplUnix::getCreationDate() const
        {
            Bull::Log::get()->write("Creation date is not available on UNIX-like systems", Log::Level::Warning);

            return Date();
        }

        /*! \brief Get the date of the last access of the file
         *
         * \return Return the date of the last access of the file
         *
         */
        Date FileImplUnix::getLastAccessDate() const
        {
            Date   lastAccess;
            struct stat64 info;
            struct tm* sysDate;

            fstat64(m_handler, &info);
            sysDate = localtime(&info.st_atim.tv_sec);

            lastAccess.second    = sysDate->tm_sec;
            lastAccess.minute    = sysDate->tm_min;
            lastAccess.hour      = sysDate->tm_hour;
            lastAccess.day       = sysDate->tm_mday;
            lastAccess.dayOfWeek = Date::Day(sysDate->tm_wday);
            lastAccess.month     = Date::Month(sysDate->tm_mon);
            lastAccess.year      = 1900 + sysDate->tm_year;

            return lastAccess;
        }

        /*! \brief Get the date of the last write of the file
         *
         * \return Return the date of the last write of the file
         *
         */
        Date FileImplUnix::getLastWriteDate() const
        {
            Date   lastWrite;
            struct stat64 info;
            struct tm* sysDate;

            fstat64(m_handler, &info);
            sysDate = localtime(&info.st_mtim.tv_sec);

            lastWrite.second    = sysDate->tm_sec;
            lastWrite.minute    = sysDate->tm_min;
            lastWrite.hour      = sysDate->tm_hour;
            lastWrite.day       = sysDate->tm_mday;
            lastWrite.dayOfWeek = Date::Day(sysDate->tm_wday);
            lastWrite.month     = Date::Month(sysDate->tm_mon);
            lastWrite.year      = 1900 + sysDate->tm_year;

            return lastWrite;
        }

        /*! \brief Get the position of the cursor in the file
         *
         * \return Return the position of the cursor in the file
         *
         */
        Uint64 FileImplUnix::getCursor() const
        {
            return lseek64(m_handler, 0, SEEK_CUR);
        }

        /*! \brief Move the reading position in the file
         *
         * \param offset The offset to move the cursor
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplUnix::moveCursor(Int64 offset)
        {
            return lseek64(m_handler, offset, SEEK_CUR);
        }

        /*! \brief Set the reading position in the file
         *
         * \param position The position to seek to
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplUnix::setCursor(Uint64 offset)
        {
            return lseek64(m_handler, offset, SEEK_SET);
        }

        /*! \brief Get the size of the file
         *
         * \return Return the size of the file
         *
         */
        Uint64 FileImplUnix::getSize() const
        {
            struct stat64 info;
            fstat64(m_handler, &info);

            return static_cast<Uint64>(info.st_size);
        }
    }
}
