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
        ImplPtr<ThreadImpl> ThreadImpl::createInstance(std::function<void()>& function, ThreadPriority priority)
        {
            return ImplPtr<ThreadImpl>::make<ThreadImplType>(function, priority);
        }

        void ThreadImpl::sleep(const Time& time)
        {
            ThreadImplType::sleep(time);
        }

        ThreadImpl::~ThreadImpl() = default;
    }
}
