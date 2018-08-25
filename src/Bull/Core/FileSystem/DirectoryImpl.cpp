#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>
    typedef Bull::prv::DirectoryImplWin32 DirectoryImplType;
#else
    #include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>
    typedef Bull::prv::DirectoryImplUnix DirectoryImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<DirectoryImpl> DirectoryImpl::createInstance(const Path& path)
        {
            return std::make_unique<DirectoryImplType>(path);
        }

        void DirectoryImpl::create(const Path& path)
        {
            DirectoryImplType::create(path);
        }

        bool DirectoryImpl::exists(const Path& path)
        {
            return DirectoryImplType::exists(path);
        }

        void DirectoryImpl::rename(const Path& path, const Path& newPath)
        {
            DirectoryImplType::rename(path, newPath);
        }

        void DirectoryImpl::remove(const Path& path)
        {
            DirectoryImplType::remove(path);
        }

        DirectoryImpl::~DirectoryImpl() = default;
    }
}

