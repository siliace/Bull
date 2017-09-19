#include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

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

        DirectoryImplWin32::~DirectoryImplWin32()
        {
            FindClose(m_handler);
        }

        bool DirectoryImplWin32::open(const Path& name)
        {
            m_base = name;

            String path = name.toString() + "\\*";

            m_handler = FindFirstFile(path.getBuffer(), &m_result);

            return m_handler != INVALID_HANDLE_VALUE;
        }

        std::vector<Path> DirectoryImplWin32::getContent(Uint32 flags)
        {
            std::vector<Path> content;

            do
            {
                Path p(m_base.toString() + "/" + m_result.cFileName);

                if((flags & (Directory::Directories) && p.isDirectory()) || (flags & (Directory::Files) && p.isFile()))
                {
                    content.push_back(p);
                }
            }while(FindNextFile(m_handler, &m_result));

            return content;
        }
    }
}
