#include <Bull/Core/Thread/SemaphoreImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/SemaphoreImplWin32.hpp>
    typedef Bull::prv::SemaphoreImplWin32 SemaphoreImplType;
#else
    #include <Bull/Core/Thread/Unix/SemaphoreImplUnix.hpp>
    typedef Bull::prv::SemaphoreImplUnix SemaphoreImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        SemaphoreImpl* SemaphoreImpl::createInstance(unsigned int count)
        {
            return new SemaphoreImplType(count);
        }

        SemaphoreImpl::~SemaphoreImpl() = default;
    }
}
