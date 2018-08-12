#include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>
#include <Bull/Core/Support/Win32/DateHelper.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

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

        FileImplWin32::~FileImplWin32()
        {
            CloseHandle(m_handler);
        }

        bool FileImplWin32::open(const Path& name, Uint32 mode)
        {
            DWORD creationMode = 0;
            DWORD openingMode  = 0;

            if(mode & FileOpeningMode_Read)
            {
                openingMode |= GENERIC_READ;

                if(!(mode & FileOpeningMode_Write))
                {
                    creationMode = (mode & FileOpeningMode_Exists) ? OPEN_EXISTING : CREATE_NEW;
                }
            }

            if(mode & FileOpeningMode_Write)
            {
                if(mode & FileOpeningMode_Append)
                {
                    openingMode |= FILE_APPEND_DATA;
                }
                else
                {
                    openingMode |= GENERIC_WRITE;
                }

                if(mode & FileOpeningMode_Truncate)
                {
                    creationMode = CREATE_ALWAYS;
                }
                else if(mode & FileOpeningMode_Exists)
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

        std::size_t FileImplWin32::read(void* data, std::size_t size)
        {
            DWORD read;
            LARGE_INTEGER cursor;
            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);
            ReadFile(m_handler, data, size, &read, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);

            return read;
        }

        std::size_t FileImplWin32::write(const void* data, std::size_t size)
        {
            DWORD written = 0;
            LARGE_INTEGER cursor;
            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);
            WriteFile(m_handler, data, static_cast<DWORD>(size), &written, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(size), 0);

            return written;
        }

        void FileImplWin32::flush()
        {
            FlushFileBuffers(m_handler);
        }

        DateTime FileImplWin32::getCreationDate() const
        {
            FILETIME date;

            Expect(
                    GetFileTime(m_handler, &date, nullptr, nullptr),
                    Throw(Win32Error, "FileImplWin32::getCreationDate", "Failed to get file creation date")
            );

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        DateTime FileImplWin32::getLastAccessDate() const
        {
            FILETIME date;

            Expect(
                    GetFileTime(m_handler, &date, nullptr, nullptr),
                    Throw(Win32Error, "FileImplWin32::getLastAccessDate", "Failed to get file last access date")
            );

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        DateTime FileImplWin32::getLastWriteDate() const
        {
            FILETIME date;

            Expect(
                    GetFileTime(m_handler, &date, nullptr, nullptr),
                    Throw(Win32Error, "FileImplWin32::getLastWriteDate", "Failed to get file last write date")
            );

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        std::size_t FileImplWin32::getCursor() const
        {
            LARGE_INTEGER zero = {0};
            LARGE_INTEGER position;

            Expect(
                    SetFilePointerEx(m_handler, zero, &position, FILE_CURRENT),
                    Throw(Win32Error, "FileImplWin32::getCursor", "Failed to get file cursor")
            );

            return static_cast<std::size_t>(position.QuadPart);
        }

        std::size_t FileImplWin32::moveCursor(Int64 offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            Expect(
                    SetFilePointerEx(m_handler, distance, &position, FILE_CURRENT),
                    Throw(Win32Error, "FileImplWin32::moveCursor", "Failed to move file cursor")
            );

            return position.QuadPart;
        }

        std::size_t FileImplWin32::setCursor(std::size_t offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            Expect(
                    SetFilePointerEx(m_handler, distance, &position, FILE_CURRENT),
                    Throw(Win32Error, "FileImplWin32::setCursor", "Failed to set file cursor")
            );

            return position.QuadPart;
        }

        std::size_t FileImplWin32::getSize() const
        {
            LARGE_INTEGER size;

            GetFileSizeEx(m_handler, &size);

            return size.QuadPart;
        }
    }
}
