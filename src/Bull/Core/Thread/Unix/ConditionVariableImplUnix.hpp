#ifndef Bull_ConditionVariableImplUnix_hpp
#define Bull_ConditionVariableImplUnix_hpp

#include <pthread.h>

#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplUnix : public ConditionVariableImpl
        {
        public:

            /*! @brief Default constructor
             *
             */
            ConditionVariableImplUnix();

            /*! @brief Destructor
             *
             */
            ~ConditionVariableImplUnix();

            /*! @brief Send a signal to a waiting thread
             *
             */
            void signalOne() override;

            /*! @brief Send a signal to all waiting thread
             *
             */
            void signalAll() override;

            /*! @brief Wait for a signal
             *
             * @param mutex The mutex to use to lock the resource
             *
             */
            void wait(MutexImpl* mutex) override;

            /*! @brief Wait for a signal
             *
             * @param mutex The mutex to use to lock the resource
             * @param timeout The time to wait before failing
             *
             * @return Return false if timeout, false otherwise
             *
             */
            bool wait(MutexImpl* mutex, const Time& timeout) override;

        private:

            pthread_cond_t m_handler;
        };
    }
}

#endif // Bull_ConditionVariableImplUnix_hpp


