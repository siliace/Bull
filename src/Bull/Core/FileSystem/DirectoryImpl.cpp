#include <Bull/Core/Configuration/OS.hpp>
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
        DirectoryImpl* DirectoryImpl::createInstance(const Path& name)
        {
            std::unique_ptr<DirectoryImplType> instance = std::make_unique<DirectoryImplType>();
            instance->open(name);
            return instance.release();
        }

        bool DirectoryImpl::create(const String& name)
        {
            return DirectoryImplType::create(name);
        }

        bool DirectoryImpl::exists(const String& name)
        {
            return DirectoryImplType::exists(name);
        }

        bool DirectoryImpl::remove(const Path& name)
        {
            return DirectoryImplType::remove(name);
        }

        DirectoryImpl::~DirectoryImpl()
        {
            /// Nothing
        }
    }
}

