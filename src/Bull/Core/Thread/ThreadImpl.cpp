#include <Bull/Core/System/Config.hpp>
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
        /*! \brief Create a OS specific instance of ThreadImpl
         *
         * \param function The function to run in the thread
         * \param priority The priority of the thread
         *
         * \return Return the created instance
         *
         */
        ThreadImpl* ThreadImpl::createInstance(Functor<void>& function, Thread::Priority priority)
        {
            return new ThreadImplType(function, priority);
        }

        /*! \brief Asleep the current thread
         *
         * \param time The time to sleep
         *
         */
        void ThreadImpl::sleep(const Time& time)
        {
            ThreadImplType::sleep(time);
        }

        /*! \brief Destructor
         *
         */
        ThreadImpl::~ThreadImpl()
        {
            /// Nothing
        }
    }
}
