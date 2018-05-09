#include <unistd.h>

#include <Bull/Core/Concurrency/Unix/ThreadImplUnix.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Exception/InternalError.hpp>

namespace Bull
{
    namespace prv
    {
        void ThreadImplUnix::sleep(const Duration& time)
        {
            usleep(static_cast<__useconds_t>(time.asMicroseconds()));
        }

        void* ThreadImplUnix::entryPoint(void* data)
        {
            pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, nullptr);

            static_cast<Runnable*>(data)->run();

            return nullptr;
        }

        ThreadImplUnix::ThreadImplUnix(Runnable* runnable, ThreadPriority priority)
        {
            pthread_attr_t attributes;
            pthread_attr_init(&attributes);

            if(pthread_create(&m_handler, &attributes, &ThreadImplUnix::entryPoint, runnable) != 0)
            {
                Throw(InternalError, "ThreadImplUnix::ThreadImplUnix", "Failed to start thread");
            }

            m_isRunning = true;
        }

        void ThreadImplUnix::wait()
        {
            if(pthread_self() != m_handler)
            {
                pthread_join(m_handler, nullptr);
            }
        }

        bool ThreadImplUnix::isRunning() const
        {
            #if defined __USE_GNU
            if(m_isRunning)
            {
                m_isRunning = pthread_tryjoin_np(m_handler, nullptr) == 0;
            }
            #endif

            return m_isRunning;
        }

        void ThreadImplUnix::terminate()
        {
            pthread_cancel(m_handler);
        }
    }
}
