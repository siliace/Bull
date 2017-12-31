#ifndef BULL_CORE_CONCURRENCY_CONDITIONVARIABLEIMPL_HPP
#define BULL_CORE_CONCURRENCY_CONDITIONVARIABLEIMPL_HPP

#include <memory>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Concurrency/MutexImpl.hpp>
#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of ConditionVariableImpl
             *
             * \return Return the created instance
             *
             */
            static std::unique_ptr<ConditionVariableImpl> createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~ConditionVariableImpl();

            /*! \brief Send a signal to a waiting thread
             *
             */
            virtual void signalOne() = 0;

            /*! \brief Send a signal to all waiting thread
             *
             */
            virtual void signalAll() = 0;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             *
             */
            virtual void wait(std::unique_ptr<MutexImpl>& mutex) = 0;

            /*! \brief Wait for a signal
             *
             * \param mutex   The mutex to lock the resource
             * \param timeout The time to wait before failing
             *
             * \return Return false if timeout, else return true
             *
             */
            virtual bool wait(std::unique_ptr<MutexImpl>& mutex, const Duration& timeout) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            ConditionVariableImpl() = default;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_CONDITIONVARIABLEIMPL_HPP

