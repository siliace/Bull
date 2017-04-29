#include <windows.h>

#include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplWin32::create(const String& name)
        {
            return CreateDirectory(name, nullptr);
        }

        bool DirectoryImplWin32::exists(const String& name)
        {
            DWORD attribs = GetFileAttributes(name);

            if(attribs == INVALID_FILE_ATTRIBUTES)
            {
                return  false;
            }

            return attribs & FILE_ATTRIBUTE_DIRECTORY;
        }

        bool DirectoryImplWin32::remove(const String& name)
        {
            return RemoveDirectory(name);
        }

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

        DirectoryImplWin32::~DirectoryImplWin32()
        {
            FindClose(m_handler);
        }

        bool DirectoryImplWin32::open(const String& name)
        {
            m_handler = FindFirstFile(name + "\\*", &m_result);

            return m_handler != INVALID_HANDLE_VALUE;
        }

        std::vector<Path> DirectoryImplWin32::getContent(Uint32 flags)
        {
            std::vector<Path> content;

            do
            {
                Path p(m_result.cFileName);

                if((flags & (Directory::Directories) && p.isDirectory) || (flags & (Directory::Files) && p.isFile))
                {
                    content.push_back(ent);
                }
            }while(FindNextFile(m_handler, &m_result));

            return content;
        }
    }
}
