#ifndef BULL_CORE_CONCURRENCY_UNIX_CONDITIONVARIABLEIMPLUNIX_HPP
#define BULL_CORE_CONCURRENCY_UNIX_CONDITIONVARIABLEIMPLUNIX_HPP

#include <pthread.h>

#include <Bull/Core/Concurrency/ConditionVariableImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplUnix : public ConditionVariableImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            ConditionVariableImplUnix();

            /*! \brief Destructor
             *
             */
            ~ConditionVariableImplUnix();

            /*! \brief Send a signal to a waiting thread
             *
             */
            void signalOne() override;

            /*! \brief Send a signal to all waiting thread
             *
             */
            void signalAll() override;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             *
             */
            void wait(std::unique_ptr<MutexImpl>& mutex) override;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             * \param timeout The time to wait before failing
             *
             * \return Return false if timeout, else return true
             *
             */
            bool wait(std::unique_ptr<MutexImpl>& mutex, const Duration& timeout) override;

        private:

            pthread_cond_t m_handler;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_UNIX_CONDITIONVARIABLEIMPLUNIX_HPP


