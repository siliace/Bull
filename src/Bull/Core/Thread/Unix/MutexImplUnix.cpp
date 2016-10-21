#include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        MutexImplUnix::MutexImplUnix() :
            m_handler(PTHREAD_MUTEX_INITIALIZER)
        {
            pthread_mutexattr_t attr;
            pthread_mutexattr_init(&attr);
            pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

            pthread_mutex_init(&m_handler, &attr);
        }

        /*! \brief Destructor
         *
         */
        MutexImplUnix::~MutexImplUnix()
        {
            unlock();
        }

        /*! \brief Try to lock the mutex
         *
         * \return Return true if the mutex was locked successfully, else return false
         *
         */
        bool MutexImplUnix::tryLock()
        {
            return pthread_mutex_trylock(&m_handler);
        }

        /*! \brief Lock the mutex
         *
         */
        void MutexImplUnix::lock()
        {
            pthread_mutex_lock(&m_handler);
        }

        /*! \brief Unlock the mutex
         *
         */
        void MutexImplUnix::unlock()
        {
            pthread_mutex_unlock(&m_handler);
        }

        /*! \brief Get the native handler
         *
         * \return Return the mutex native handler
         *
         */
        MutexHandler MutexImplUnix::getSystemHandler() const
        {
            return m_handler;
        }

        /*! \brief Get a pointer to the handler
         *
         * Used only by ConditionalVariableImplUnix
         *
         * \return Return a pointer to the system handler
         * \see ConditionalVariableImplUnix
         */
        MutexHandler* MutexImplUnix::getHandlerPointer()
        {
            return &m_handler;
        }
    }
}
