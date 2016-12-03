#include <windows.h>

#include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a directory
         *
         * \param name The name of the directory to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        bool DirectoryImplWin32::create(const String& name)
        {
            return CreateDirectory(name, nullptr);
        }

        /*! \brief Check if a directory exists
         *
         * \param name The name of the directory to check
         *
         * \return Return true if the directory exists, false otherwise
         *
         */
        bool DirectoryImplWin32::exists(const String& name)
        {
            DWORD attribs = GetFileAttributes(name);

            if(attribs == INVALID_FILE_ATTRIBUTES)
            {
                return  false;
            }

            return attribs & FILE_ATTRIBUTE_DIRECTORY;
        }

        /*! \brief Delete a directory
         *
         * \param name The name of the directory to delete
         *
         * \return Return true if the directory was deleted successfully, false otherwise
         *
         */
        bool DirectoryImplWin32::remove(const String& name)
        {
            return RemoveDirectory(name);
        }

        /*! \brief Convert a SYSTEMTIME to a Bull::Date
         *
         * \param sysTime The SYSTEMTIME to convert
         *
         * \return Return the equivalent Bull::Date
         *
         */
        Date DirectoryImplWin32::systemTimeToDate(SYSTEMTIME sysTime)
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
        DirectoryImplWin32::~DirectoryImplWin32()
        {
            FindClose(m_handler);
        }

        /*! \brief Constructor
         *
         * \param name The name of the directory to open
         *
         */
        bool DirectoryImplWin32::open(const String& name)
        {
            m_handler = FindFirstFile(name + "\\*", &m_result);

            return m_handler != INVALID_HANDLE_VALUE;
        }

        /*! \brief Get the content of this Directory
         *
         * \param flags What we have to look for
         *
         * \return Return the list of content entity
         *
         */
        std::vector<Path> DirectoryImplWin32::getContent(Uint32 flags)
        {
            std::vector<Path> content;

            do
            {
                LARGE_INTEGER size;
                Path ent;

                ent.isDirectory = m_result.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
                ent.isFile      = !ent.isDirectory;

                if((flags & (Directory::Directories) && ent.isDirectory) || (flags & (Directory::Files) && ent.isFile))
                {
                    SYSTEMTIME creationDate;
                    FileTimeToSystemTime(&m_result.ftCreationTime, &creationDate);

                    SYSTEMTIME lastAccessDate;
                    FileTimeToSystemTime(&m_result.ftLastAccessTime, &lastAccessDate);

                    SYSTEMTIME lastWriteTime;
                    FileTimeToSystemTime(&m_result.ftLastWriteTime, &lastWriteTime);

                    size.LowPart  = m_result.nFileSizeLow;
                    size.HighPart = m_result.nFileSizeHigh;

                    ent.pathName       = m_result.cFileName;
                    ent.size           = size.QuadPart;
                    ent.creationDate   = systemTimeToDate(creationDate);
                    ent.lastAccessDate = systemTimeToDate(lastAccessDate);
                    ent.lastWriteDate  = systemTimeToDate(lastWriteTime);

                    content.push_back(ent);
                }
            }while(FindNextFile(m_handler, &m_result));

            return content;
        }

        /*! \brief Get the directory system handler
         *
         * \return Return the native directory system handler
         *
         */
        DirectoryHandler DirectoryImplWin32::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
