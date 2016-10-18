#include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>

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
        bool FileImplWin32::create(const String& name)
        {
            HANDLE handler = CreateFile(name,
                                        GENERIC_READ | GENERIC_WRITE,
                                        FILE_SHARE_READ,
                                        nullptr,
                                        CREATE_NEW,
                                        FILE_ATTRIBUTE_NORMAL,
                                        nullptr);

            if(handler != INVALID_HANDLE_VALUE)
            {
                CloseHandle(handler);

                return true;
            }

            return false;
        }

        /*! \brief Check if a file exists
         *
         * \param name The name of the file to check
         *
         * \return Return true if the file exists, false otherwise
         *
         */
        bool FileImplWin32::exists(const String& name)
        {
            DWORD attribs = GetFileAttributes(name);

            return (attribs != INVALID_FILE_ATTRIBUTES &&  !(attribs & FILE_ATTRIBUTE_DIRECTORY));
        }

        /*! \brief Copy a file
         *
         * \param path The path (relative or absolute) of the file to copy
         * \param path The new path (relative or absolute) of the file
         *
         * \return Return true if the copy was successfully, false otherwise
         *
         */
        bool FileImplWin32::copy(const String& path, const String& newPath)
        {
            return CopyFile(path, newPath, true);
        }

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         * \return Return true if the file was deleted successfully, false otherwise
         *
         */
        bool FileImplWin32::remove(const String& name)
        {
            return DeleteFile(name);
        }

        /*! \brief Convert a SYSTEMTIME to a Bull::Date
         *
         * \param sysTime The SYSTEMTIME to convert
         *
         * \return Return the equivalent Bull::Date
         *
         */
        Date FileImplWin32::systemTimeToDate(SYSTEMTIME sysTime)
        {
            Date date;

            date.year      = sysTime.wYear;
            date.month     = Date::Month(sysTime.wMonth);
            date.day       = sysTime.wDay;
            date.dayOfWeek = Date::Day(sysTime.wDayOfWeek);
            date.hour      = sysTime.wHour;
            date.minute    = sysTime.wMinute;
            date.second    = Time::seconds(sysTime.wSecond) + Time::milliseconds(sysTime.wMilliseconds);

            return date;
        }

        /*! \brief Destructor
         *
         */
        FileImplWin32::~FileImplWin32()
        {
            CloseHandle(m_handler);
        }

        /*! \brief Open the file
         *
         * \param name The name of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         * \return Return true if the file was open successfully, false otherwise
         *
         */
        bool FileImplWin32::open(const String& name, Uint32 mode)
        {
            DWORD creationMode = 0;
            DWORD openingMode  = 0;

            if(mode & File::OpeningMode::Read)
            {
                openingMode |= GENERIC_READ;

                if(!(mode & File::OpeningMode::Write))
                {
                    creationMode = (mode & File::Exists) ? OPEN_EXISTING : CREATE_NEW;
                }
            }

            if(mode & File::OpeningMode::Write)
            {
                if(mode & File::OpeningMode::Append)
                {
                    openingMode |= FILE_APPEND_DATA;
                }
                else
                {
                    openingMode |= GENERIC_WRITE;
                }

                if(mode & File::Truncate)
                {
                    creationMode = CREATE_ALWAYS;
                }
                else if(mode & File::Exists)
                {
                    creationMode = OPEN_EXISTING;
                }
                else
                {
                    creationMode = exists(name) ? OPEN_EXISTING : CREATE_NEW;
                }
            }

            m_handler = CreateFile(name,
                                   openingMode,
                                   FILE_SHARE_READ,
                                   nullptr,
                                   creationMode,
                                   FILE_ATTRIBUTE_NORMAL,
                                   nullptr);

            return m_handler != INVALID_HANDLE_VALUE;
        }

        /*! \brief Read in a file
         *
         * \param data The destination of the read data
         * \param size The number of byte to read
         *
         * \param Return the number of byte read
         *
         */
        Uint64 FileImplWin32::read(void* data, Uint64 size)
        {
            DWORD read = 0;

            if(ReadFile(m_handler, data, size, &read, nullptr) && read > 0)
            {
                return read;
            }

            return 0;
        }

        /*! \brief Write a byte in this file
         *
         * \param byte A byte to write
         *
         */
        Uint64 FileImplWin32::write(const void* data, Uint64 size)
        {
            DWORD read = 0;

            if(WriteFile(m_handler, data, size, &read, nullptr) && read > 0)
            {
                return read;
            }

            return 0;
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the creation of the file
         *
         */
        Date FileImplWin32::getCreationDate() const
        {
            FILETIME date;

            if(GetFileTime(m_handler, &date, nullptr, nullptr))
            {
                SYSTEMTIME sysDate;
                FileTimeToSystemTime(&date, &sysDate);

                return systemTimeToDate(sysDate);
            }

            return Date();
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last access of the file
         *
         */
        Date FileImplWin32::getLastAccessDate() const
        {
            FILETIME date;

            if(GetFileTime(m_handler, nullptr, &date, nullptr))
            {
                SYSTEMTIME sysDate;
                FileTimeToSystemTime(&date, &sysDate);

                return systemTimeToDate(sysDate);
            }

            return Date();
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last write of the file
         *
         */
        Date FileImplWin32::getLastWriteDate() const
        {
            FILETIME date;

            if(GetFileTime(m_handler, nullptr, nullptr, &date))
            {
                SYSTEMTIME sysDate;
                FileTimeToSystemTime(&date, &sysDate);

                return systemTimeToDate(sysDate);
            }

            return Date();
        }

        /*! \brief Get the position of the cursor in the file
         *
         * \return Return the position of the cursor in the file
         *
         */
        Uint64 FileImplWin32::getCursor() const
        {
            LARGE_INTEGER zero = {0};
            LARGE_INTEGER position;

            if(!SetFilePointerEx(m_handler, zero, &position, FILE_CURRENT))
            {
                return 0;
            }

            return position.QuadPart;
        }

        /*! \brief Move the file cursor position
         *
         * \param offset The offset to move the cursor
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplWin32::moveCursor(Int64 offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            if(SetFilePointerEx(m_handler, distance, &position, FILE_CURRENT) == 0)
            {
                return 0;
            }

            return position.QuadPart;
        }

        /*! \brief Set the file cursor position
         *
         * \param offset The new position of the cursor
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplWin32::setCursor(Uint64 offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            if(SetFilePointerEx(m_handler, distance, &position, FILE_BEGIN) == 0)
            {
                return 0;
            }

            return position.QuadPart;
        }

        /*! \brief Get the size of the file
         *
         * \return Return the size of the file
         *
         */
        Uint64 FileImplWin32::getSize() const
        {
            LARGE_INTEGER size;

            GetFileSizeEx(m_handler, &size);

            return size.QuadPart;
        }

        /*! \brief Get the file system handler
         *
         * \return Return the native file system handler
         *
         */
        FileHandler FileImplWin32::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
