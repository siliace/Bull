#include <Bull/Core/Thread/ThreadImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/ThreadImplWin32.hpp>
    typedef Bull::prv::ThreadImplWin32 ThreadImplType;
#else
    #include <Bull/Core/Thread/Unix/ThreadImplUnix.hpp>
    typedef Bull::prv::ThreadImplUnix ThreadImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<ThreadImpl> ThreadImpl::createInstance(std::function<void()>& function, ThreadPriority priority)
        {
            return std::make_unique<ThreadImplType>(function, priority);
        }

        void ThreadImpl::sleep(const Time& time)
        {
            ThreadImplType::sleep(time);
        }

        ThreadImpl::~ThreadImpl() = default;
    }
}
