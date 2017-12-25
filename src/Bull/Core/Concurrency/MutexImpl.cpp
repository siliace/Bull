#include <Bull/Core/Concurrency/Mutex.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Concurrency/Win32/MutexImplWin32.hpp>
    typedef Bull::prv::MutexImplWin32 MutexImplType;
#else
    #include <Bull/Core/Concurrency/Unix/MutexImplUnix.hpp>
    typedef Bull::prv::MutexImplUnix MutexImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<MutexImpl> MutexImpl::createInstance()
        {
            return std::make_unique<MutexImplType>();
        }

        MutexImpl::~MutexImpl() = default;
    }
}
