#ifndef BULL_CORE_THREAD_CONDITIONVARIABLE_HPP
#define BULL_CORE_THREAD_CONDITIONVARIABLE_HPP

#include <memory>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImpl;
    }

    class BULL_CORE_API ConditionVariable : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        ConditionVariable();

        /*! \brief Destructor
         *
         */
        virtual ~ConditionVariable();

        /*! \brief Send a signal to a waiting thread
         *
         */
        void signalOne();

        /*! \brief Send a signal to all waiting thread
         *
         */
        void signalAll();

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to lock the resource
         *
         */
        void wait(Mutex& mutex);

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to lock the resource
         * \param timeout The time to wait before failing
         *
         * \return Return false if timeout, else return true
         *
         */
        bool wait(Mutex& mutex, const Time& timeout);

    private:

        std::unique_ptr<prv::ConditionVariableImpl> m_impl;
    };
}

#endif // BULL_CORE_THREAD_CONDITIONVARIABLE_HPP
