#include <cstdio>

#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

namespace Bull
{
    void Directory::create(const Path& path)
    {
        prv::DirectoryImpl::create(path);
    }

    bool Directory::exists(const Path& path)
    {
        return prv::DirectoryImpl::exists(path);
    }

    void Directory::copy(const Path& path, const Path& newPath)
    {
        Directory target(path);

        if(!Directory::exists(newPath))
        {
            Directory::create(newPath);
        }

        for(const Path& p : target.getContent())
        {
            if(p.isDirectory())
            {
                Directory::copy(path.resolve(p.toString()), newPath.resolve(p.toString()));
            }
            else
            {
                File::copy(path.resolve(p.toString()), newPath.resolve(p.toString()));
            }
        }
    }

    void Directory::rename(const Path& path, const Path& newPath)
    {
        prv::DirectoryImpl::rename(path, newPath);
    }

    void Directory::remove(const Path& path)
    {
        prv::DirectoryImpl::remove(path);
    }

    Directory::Directory(const Path& path)
    {
        open(path);
    }

    Directory::~Directory() = default;

    void Directory::open(const Path& path)
    {
        m_path = path;
        m_impl = prv::DirectoryImpl::createInstance(path);
    }

    std::vector<Path> Directory::getContent(Uint32 flags)
    {
        return m_impl->getContent(flags);
    }

    const Path& Directory::getPath() const
    {
        return m_path;
    }
}
