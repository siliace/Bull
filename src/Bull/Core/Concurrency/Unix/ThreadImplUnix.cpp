#include <unistd.h>

#include <Bull/Core/Concurrency/Unix/ThreadImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        void ThreadImplUnix::sleep(const Time& time)
        {
            usleep(static_cast<__useconds_t>(time.asMicroseconds()));
        }

        void* ThreadImplUnix::entryPoint(void* data)
        {
            Functor<void>* function = static_cast<Functor<void>*>(data);

            function->run();

            return nullptr;
        }

        ThreadImplUnix::ThreadImplUnix(Functor<void>& function, ThreadPriority priority)
        {
            pthread_attr_t attributes;
            pthread_attr_init(&attributes);
            pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_DETACHED);

            if(priority == ThreadPriority_Inherit)
            {
                pthread_attr_setinheritsched(&attributes, PTHREAD_INHERIT_SCHED);
            }

            pthread_create(&m_handler, &attributes, &ThreadImplUnix::entryPoint, &function);
        }

        void ThreadImplUnix::wait()
        {
            if(pthread_self() != m_handler)
            {
                pthread_join(m_handler, nullptr);
            }
        }

        void ThreadImplUnix::stop()
        {
            pthread_detach(m_handler);
        }
    }
}
