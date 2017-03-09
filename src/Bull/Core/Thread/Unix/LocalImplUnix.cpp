#include <Bull/Core/Thread/Unix/LocalImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        LocalImplUnix::LocalImplUnix() :
            m_handler(0)
        {
            pthread_key_create(&m_handler, nullptr);
        }

        LocalImplUnix::~LocalImplUnix()
        {
            pthread_key_delete(m_handler);
        }

        void LocalImplUnix::set(void* value)
        {
            pthread_setspecific(m_handler, value);
        }

        void* LocalImplUnix::get() const
        {
            return pthread_getspecific(m_handler);
        }
    }
}
