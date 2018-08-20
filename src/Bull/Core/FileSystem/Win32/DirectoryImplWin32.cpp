#include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        bool DirectoryImplWin32::create(const String& name)
        {
            return CreateDirectory(name.getBuffer(), nullptr) == TRUE;
        }

        bool DirectoryImplWin32::exists(const String& name)
        {
            DWORD attribs = GetFileAttributes(name.getBuffer());

            if(attribs == INVALID_FILE_ATTRIBUTES)
            {
                return  false;
            }

            return attribs & FILE_ATTRIBUTE_DIRECTORY;
        }

        bool DirectoryImplWin32::remove(const Path& name)
        {
            return RemoveDirectory(name.toString().getBuffer()) == TRUE;
        }

        DirectoryImplWin32::DirectoryImplWin32(const String& path) :
            m_path(path)
        {
            String base = m_path + "\\*";

            m_handler = FindFirstFile(path.getBuffer(), &m_result);

            Expect(m_handler != INVALID_HANDLE_VALUE, Throw(Win32Error, "DirectoryImplWin32::DirectoryImplWin32", "Failed to open directory " + m_path));
        }

        DirectoryImplWin32::~DirectoryImplWin32()
        {
            FindClose(m_handler);
        }

        std::vector<Path> DirectoryImplWin32::getContent(Uint32 flags)
        {
            std::vector<Path> content;

            do
            {
                Path p(m_path + "/" + m_result.cFileName);

                if((flags & (DirectorySearchFlag_Directories) && p.isDirectory()) || (flags & (DirectorySearchFlag_Files) && p.isFile()))
                {
                    content.push_back(p);
                }
            }while(FindNextFile(m_handler, &m_result));

            return content;
        }
    }
}
