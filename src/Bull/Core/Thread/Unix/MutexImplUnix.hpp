#ifndef Bull_MutexImplUnix_hpp
#define Bull_MutexImplUnix_hpp

#include <pthread.h>

#include <Bull/Core/Thread/MutexImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class MutexImplUnix : public MutexImpl
        {
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

            /*! \brief Get the native handler
             *
             * \return Return the mutex native handler
             *
             */
            MutexHandler getSystemHandler() const override;

        private:

            pthread_mutex_t m_handler;
        };
    }
}

#endif // Bull_MutexImplUnix_hpp
