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
        ThreadImpl* ThreadImpl::createInstance(Functor<void>& function, Thread::Priority priority)
        {
            return new ThreadImplType(function, priority);
        }

        void ThreadImpl::sleep(const Time& time)
        {
            ThreadImplType::sleep(time);
        }

        ThreadImpl::~ThreadImpl()
        {
            /// Nothing
        }
    }
}
