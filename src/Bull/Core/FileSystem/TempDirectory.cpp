#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/TempDirectory.hpp>

namespace Bull
{
    TempDirectory::TempDirectory(const String& name, const Path& path)
    {
        String fullPath = Path::canonical(path).toString() + Path::Separator + name;

        if(!Directory::exists(fullPath))
        {
            if(!Directory::create(fullPath))
            {
                throw RuntimeError("Failed to create temporary directory");
            }
        }

        if(!open(Path(fullPath)))
        {
            throw RuntimeError("Failed to open temporary directory");
        }
    }

    FileRef TempDirectory::createFile(const String& name)
    {
        String fullPath = getPath().toString() + Path::Separator + name;

        if(!File::exists(fullPath))
        {
            if(!File::create(fullPath))
            {

            }
        }

        return File::make(Path(fullPath));
    }

    DirectoryRef TempDirectory::createDirectory(const String& name)
    {
        String fullPath = getPath().toString() + Path::Separator + name;

        if(!Directory::exists(fullPath))
        {
            Directory::create(fullPath);
        }

        return TempDirectory::make(Path(fullPath));
    }
}