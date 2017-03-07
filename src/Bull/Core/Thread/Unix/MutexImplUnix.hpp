#ifndef Bull_MutexImplUnix_hpp
#define Bull_MutexImplUnix_hpp

#include <pthread.h>

#include <Bull/Core/Thread/MutexImpl.hpp>

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

        private:

            pthread_mutex_t m_handler;
        };
    }
}

#endif // Bull_MutexImplUnix_hpp
