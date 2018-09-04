#include <Bull/Core/FileSystem/DirectorySearchFlag.hpp>
#include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        void DirectoryImplWin32::create(const Path& path)
        {
            Expect(
                    CreateDirectory(path.toString().getBuffer(), nullptr),
                    Throw(Win32Error, "DirectoryImplWin32::create", "Failed to create the directory " + path.toString())
            );
        }

        bool DirectoryImplWin32::exists(const Path& path)
        {
            DWORD attribs = GetFileAttributes(path.toString().getBuffer());

            return (attribs != INVALID_FILE_ATTRIBUTES) && (attribs & FILE_ATTRIBUTE_DIRECTORY);
        }

        void DirectoryImplWin32::rename(const Path& path, const Path& newPath)
        {
            Expect(
                MoveFile(path.toString().getBuffer(), newPath.toString().getBuffer()),
                Throw(Win32Error, "DirectoryImplWin32::rename", "Failed to rename the directory " + path.toString())
            );
        }

        void DirectoryImplWin32::remove(const Path& path)
        {
            Expect(
                    RemoveDirectory(path.toString().getBuffer()),
                    Throw(Win32Error, "DirectoryImplWin32::remove", "Failed to remove the directory " + path.toString())
            );
        }

        DirectoryImplWin32::DirectoryImplWin32(const Path& path) :
            m_path(path)
        {
            String base = m_path.toString() + "\\*";

            m_handler = FindFirstFile(base.getBuffer(), &m_result);

            Expect(m_handler != INVALID_HANDLE_VALUE, Throw(Win32Error, "DirectoryImplWin32::DirectoryImplWin32", "Failed to open directory " + m_path.toString()));
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
                String fileName = m_result.cFileName;

                if(fileName != "." && fileName != "..")
                {
                    Path child = m_path.resolve(m_result.cFileName);

                    if((child.isFile() && (flags & DirectorySearchFlag_Files)) || (child.isDirectory() && (flags & DirectorySearchFlag_Directories)))
                    {
                        content.push_back(child);
                    }
                }
            }while(FindNextFile(m_handler, &m_result));

            return content;
        }
    }
}
