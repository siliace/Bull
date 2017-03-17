#include <cstdio>

#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/FileSystem/File.hpp>

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

    bool Directory::copy(const String& path, const String& newPath)
    {
        Directory target;
        bool success = true;

        if(!target.open(Path(path)))
        {
            return false;
        }

        if(!Directory::exists(newPath))
        {
            Directory::create(newPath);
        }

        for(const Path& entity : target.getContent())
        {
            if(entity.getPathName() != "." && entity.getPathName() != "..")
            {
                if(entity.isDirectory())
                {
                    success &= Directory::copy(path + "/" + entity.getPathName(), newPath + "/" + entity.getPathName());
                }
                else
                {
                    success &= File::copy(path + "/" + entity.getPathName(), newPath + "/" + entity.getPathName());
                }
            }
        }

        return success;
    }

    bool Directory::rename(const String& path, const String& newPath)
    {
        if(exists(path) && !exists(newPath))
        {
            return std::rename(path, newPath) == 0;
        }

        return false;
    }

    bool Directory::remove(const String& path)
    {
        return prv::DirectoryImpl::remove(path);
    }

    Directory::Directory()
    {
        /// Nothing
    }

    Directory::Directory(const Path& path)
    {
        open(path);
    }

    Directory::~Directory()
    {
        close();
    }

    bool Directory::open(const Path& path)
    {
        m_path = path;

        m_impl.reset(prv::DirectoryImpl::createInstance(path));

        return true;
    }

    bool Directory::isOpen() const
    {
        return m_impl.get() != nullptr;
    }

    void Directory::close()
    {
        m_impl.reset();
        m_path = Path::None;
    }

    std::vector<Path> Directory::getContent(Uint32 flags)
    {
        if(m_impl)
        {
            return m_impl->getContent(flags);
        }

        return std::vector<Path>();
    }

    const Path& Directory::getPath() const
    {
        return m_path;
    }
}
