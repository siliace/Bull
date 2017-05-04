#include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        bool FileImplWin32::create(const String& name)
        {
            HANDLE handler = CreateFile(name.getBuffer(),
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

        bool FileImplWin32::exists(const String& name)
        {
            DWORD attribs = GetFileAttributes(name.getBuffer());

            return (attribs != INVALID_FILE_ATTRIBUTES &&  !(attribs & FILE_ATTRIBUTE_DIRECTORY));
        }

        bool FileImplWin32::copy(const Path& path, const String& newPath)
        {
            return CopyFile(path.toString().getBuffer(), newPath.getBuffer(), true) == TRUE;
        }

        bool FileImplWin32::remove(const Path& name)
        {
            return DeleteFile(name.toString().getBuffer()) == TRUE;
        }

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

        FileImplWin32::~FileImplWin32()
        {
            CloseHandle(m_handler);
        }

        bool FileImplWin32::open(const Path& name, Uint32 mode)
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
                    creationMode = exists(name.toString()) ? OPEN_EXISTING : CREATE_NEW;
                }
            }

            m_handler = CreateFile(name.toString().getBuffer(),
                                   openingMode,
                                   FILE_SHARE_READ,
                                   nullptr,
                                   creationMode,
                                   FILE_ATTRIBUTE_NORMAL,
                                   nullptr);

            return m_handler != INVALID_HANDLE_VALUE;
        }

        Uint64 FileImplWin32::read(void* data, Uint64 size)
        {
            LARGE_INTEGER cursor;
            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);
            DWORD read = ReadFile(m_handler, data, size, &read, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);

            return 0;
        }

        Uint64 FileImplWin32::write(const void* data, Uint64 size)
        {
            DWORD written = 0;
            LARGE_INTEGER cursor;
            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);
            WriteFile(m_handler, data, static_cast<DWORD>(size), &written, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);

            return written;
        }

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

        Uint64 FileImplWin32::getSize() const
        {
            LARGE_INTEGER size;

            GetFileSizeEx(m_handler, &size);

            return size.QuadPart;
        }
    }
}
