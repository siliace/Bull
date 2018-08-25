#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>
#include "FileImpl.hpp"

typedef Bull::prv::FileImplWin32 FileImplType;
#else
    #include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>
    typedef Bull::prv::FileImplUnix FileImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<FileImpl> FileImpl::createInstance(const Path& path, Uint32 mode)
        {
            return std::make_unique<FileImplType>(path, mode);
        }

        void FileImpl::create(const Path& path)
        {
            FileImplType::create(path);
        }

        bool FileImpl::exists(const Path& path)
        {
            return FileImplType::exists(path);
        }

        void FileImpl::copy(const Path& path, const Path& newPath)
        {
            FileImplType::copy(path, newPath);
        }

        void FileImpl::rename(const Path& path, const Path& newPath)
        {
            FileImplType::rename(path, newPath);
        }

        void FileImpl::remove(const Path& path)
        {
            FileImplType::remove(path);
        }

        FileImpl::~FileImpl() = default;
    }
}
