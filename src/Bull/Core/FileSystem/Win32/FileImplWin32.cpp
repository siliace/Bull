#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>
#include <Bull/Core/Support/Win32/DateHelper.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        void FileImplWin32::create(const Path& path)
        {
            HANDLE handler = CreateFile(path.toString().c_str(),
                                        GENERIC_READ | GENERIC_WRITE,
                                        FILE_SHARE_READ,
                                        nullptr,
                                        CREATE_NEW,
                                        FILE_ATTRIBUTE_NORMAL,
                                        nullptr);

            Expect(handler != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to create file " + path.toString()));

            CloseHandle(handler);
        }

        bool FileImplWin32::exists(const Path& name)
        {
            DWORD attribs = GetFileAttributes(name.toString().c_str());

            return (attribs != INVALID_FILE_ATTRIBUTES && !(attribs & FILE_ATTRIBUTE_DIRECTORY));
        }

        void FileImplWin32::copy(const Path& path, const Path& newPath)
        {
            Expect(CopyFile(path.toString().c_str(), newPath.toString().c_str(), true), Throw(Win32Error, "Failed to copy file " + path.toString()));
        }

        void FileImplWin32::rename(const Path& path, const Path& newPath)
        {
            Expect(MoveFile(path.toString().c_str(), newPath.toString().c_str()), Throw(Win32Error, "Failed to rename file " + path.toString()));
        }

        void FileImplWin32::remove(const Path& path)
        {
            Expect(DeleteFile(path.toString().c_str()), Throw(Win32Error, "Failed to remove file " + path.toString()));
        }

        FileImplWin32::FileImplWin32(const Path& path, Uint32 mode)
        {
            DWORD creationMode = 0;
            DWORD openingMode = 0;

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
                    creationMode = exists(path) ? OPEN_EXISTING : CREATE_NEW;
                }
            }

            m_handler = CreateFile(path.toString().c_str(),
                                   openingMode,
                                   FILE_SHARE_READ,
                                   nullptr,
                                   creationMode,
                                   FILE_ATTRIBUTE_NORMAL,
                                   nullptr);

            Expect(m_handler != INVALID_HANDLE_VALUE, Throw(Win32Error, "Failed to open file " + path.toString()));
        }

        FileImplWin32::~FileImplWin32()
        {
            CloseHandle(m_handler);
        }

        ByteArray FileImplWin32::read(std::size_t length)
        {
            DWORD read;
            std::string buffer;
            LARGE_INTEGER cursor;

            ByteArray bytes(length);

            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(length), 0);
            ReadFile(m_handler, &bytes[0], length, &read, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(length), 0);

            bytes.resize(read);

            return bytes;
        }

        std::size_t FileImplWin32::write(const ByteArray& bytes)
        {
            DWORD written = 0;
            LARGE_INTEGER cursor;

            cursor.QuadPart = getCursor();

            LockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(bytes.getCapacity()), 0);
            BOOL success = WriteFile(m_handler, bytes.getBuffer(), static_cast<DWORD>(bytes.getCapacity()), &written, nullptr);
            UnlockFile(m_handler, cursor.LowPart, cursor.HighPart, static_cast<DWORD>(bytes.getCapacity()), 0);

            Expect(success, Throw(Win32Error, "Failed to write into file"));

            return written;
        }

        void FileImplWin32::flush()
        {
            FlushFileBuffers(m_handler);
        }

        DateTime FileImplWin32::getCreationDate() const
        {
            FILETIME date;

            Expect(GetFileTime(m_handler, &date, nullptr, nullptr), Throw(Win32Error, "Failed to get file creation date"));

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        DateTime FileImplWin32::getLastAccessDate() const
        {
            FILETIME date;

            Expect(GetFileTime(m_handler, &date, nullptr, nullptr), Throw(Win32Error, "Failed to get file last access date"));

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        DateTime FileImplWin32::getLastWriteDate() const
        {
            FILETIME date;

            Expect(GetFileTime(m_handler, &date, nullptr, nullptr), Throw(Win32Error, "Failed to get file last write date"));

            SYSTEMTIME sysDate;
            FileTimeToSystemTime(&date, &sysDate);

            return systemTimeToDate(sysDate);
        }

        std::size_t FileImplWin32::getCursor() const
        {
            LARGE_INTEGER zero = {0};
            LARGE_INTEGER position;

            Expect(SetFilePointerEx(m_handler, zero, &position, FILE_CURRENT), Throw(Win32Error, "Failed to get file cursor"));

            return static_cast<std::size_t>(position.QuadPart);
        }

        std::size_t FileImplWin32::moveCursor(Int64 offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            Expect(SetFilePointerEx(m_handler, distance, &position, FILE_CURRENT), Throw(Win32Error, "Failed to move file cursor"));

            return position.QuadPart;
        }

        std::size_t FileImplWin32::setCursor(std::size_t offset)
        {
            LARGE_INTEGER distance;
            LARGE_INTEGER position;
            distance.QuadPart = offset;

            Expect(SetFilePointerEx(m_handler, distance, &position, FILE_BEGIN), Throw(Win32Error, "Failed to set file cursor"));

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
