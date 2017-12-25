#ifndef BULL_CORE_CONCURRENCY_UNIX_MUTEXIMPLUNIX_HPP
#define BULL_CORE_CONCURRENCY_UNIX_MUTEXIMPLUNIX_HPP

#include <pthread.h>

#include <Bull/Core/Concurrency/MutexImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplUnix;

        class MutexImplUnix : public MutexImpl
        {
            friend class ConditionVariableImplUnix;

        public:

            /*! \brief Default constructor
             *
             */
            MutexImplUnix();

            /*! \brief Destructor
             *
             */
            ~MutexImplUnix();

            /*! \brief Try to lock the mutex
             *
             * \return Return true if the mutex was locked successfully, else return false
             *
             */
            bool tryLock() override;

            /*! \brief Lock the mutex
             *
             */
            void lock() override;

            /*! \brief Unlock the mutex
             *
             */
            void unlock() override;

            /*! \brief Get the mutex handler
             *
             * \return The handler
             *
             */
            MutexHandler* getHandler() override;

        private:

            pthread_mutex_t m_handler;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_UNIX_MUTEXIMPLUNIX_HPP
