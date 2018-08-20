#include <cstdio>

#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    bool Directory::create(const String& path)
    {
        return prv::DirectoryImpl::create(path);
    }

    bool Directory::exists(const String& path)
    {
        return prv::DirectoryImpl::exists(path);
    }

    bool Directory::copy(const Path& path, const String& newPath)
    {
        bool success = true;
        Directory target = path.toDirectory();

        if(!Directory::exists(newPath))
        {
            Directory::create(newPath);
        }

        for(const Path& entity : target.getContent())
        {
            if(entity.toString() != "." && entity.toString() != "..")
            {
                if(entity.isDirectory())
                {
                    success &= Directory::copy(Path(path.toString() + Path::Separator + entity.toString()), newPath + Path::Separator + entity.toString());
                }
                else
                {
                    success &= File::copy(Path(path.toString() + Path::Separator + entity.toString()), newPath + Path::Separator + entity.toString());
                }
            }
        }

        return success;
    }

    bool Directory::rename(const Path& path, const String& newPath)
    {
        if(exists(path.toString()) && !exists(newPath))
        {
            return std::rename(path.toString().getBuffer(), newPath.getBuffer()) == 0;
        }

        return false;
    }

    bool Directory::remove(const Path& path)
    {
        return prv::DirectoryImpl::remove(path);
    }

    std::vector<Path> Directory::getContent(Uint32 flags)
    {
        std::vector<Path> entities;

        if(m_impl)
        {
            entities = m_impl->getContent(flags);
        }

        return entities;
    }

    const String& Directory::getPath() const
    {
        return m_path;
    }

    Directory::Directory(const String& path)
    {
        m_path = path;
        m_impl = prv::DirectoryImpl::createInstance(path);
    }
}
