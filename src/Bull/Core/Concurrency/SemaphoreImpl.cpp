#include <Bull/Core/Concurrency/SemaphoreImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Concurrency/Win32/SemaphoreImplWin32.hpp>
    typedef Bull::prv::SemaphoreImplWin32 SemaphoreImplType;
#else
    #include <Bull/Core/Concurrency/Unix/SemaphoreImplUnix.hpp>
    typedef Bull::prv::SemaphoreImplUnix SemaphoreImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<SemaphoreImpl> SemaphoreImpl::createInstance(unsigned int count)
        {
            return std::make_unique<SemaphoreImplType>(count);
        }

        SemaphoreImpl::~SemaphoreImpl() = default;
    }
}
