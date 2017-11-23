#include <Bull/Core/Thread/Mutex.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/MutexImplWin32.hpp>
    typedef Bull::prv::MutexImplWin32 MutexImplType;
#else
    #include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>
    typedef Bull::prv::MutexImplUnix MutexImplType;
#endif

namespace Bull
{
    namespace prv
    {
        ImplPtr<MutexImpl> MutexImpl::createInstance()
        {
            return ImplPtr<MutexImpl>::make<MutexImplType>();
        }

        MutexImpl::~MutexImpl() = default;
    }
}
