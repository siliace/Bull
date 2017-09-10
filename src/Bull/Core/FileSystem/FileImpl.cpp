#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>
    typedef Bull::prv::FileImplWin32 FileImplType;
#else
    #include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>
    typedef Bull::prv::FileImplUnix FileImplType;
#endif

namespace Bull
{
    namespace prv
    {
        FileImpl* FileImpl::createInstance(const Path& name, Uint32 mode)
        {
            FileImplType* impl = new FileImplType();

            if(impl->open(name, mode))
            {
                return impl;
            }

            delete impl;
            return nullptr;
        }

        bool FileImpl::create(const String& name)
        {
            return FileImplType::create(name);
        }

        bool FileImpl::exists(const String& name)
        {
            return FileImplType::exists(name);
        }

        bool FileImpl::copy(const Path& path, const String& newPath)
        {
            return FileImplType::copy(path, newPath);
        }

        bool FileImpl::remove(const Path& name)
        {
            return FileImplType::remove(name);
        }

        FileImpl::~FileImpl() = default;
    }
}
