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
        Directory target(path);
        bool success = true;

        if(!Directory::exists(newPath))
        {
            Directory::create(newPath);
        }

        if(!target.isOpen())
        {
            return false;
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
            return ::rename(path, newPath);
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

    Directory::Directory(const String& path)
    {
        open(path);
    }

    Directory::~Directory()
    {
        close();
    }

    bool Directory::open(const String& path)
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
        m_path.clear();
        m_impl.reset();
    }

    std::vector<Path> Directory::getContent(Uint32 flags)
    {
        if(m_impl)
        {
            return m_impl->getContent(flags);
        }

        return std::vector<Path>();
    }

    String Directory::getPath() const
    {
        return m_path;
    }
}
