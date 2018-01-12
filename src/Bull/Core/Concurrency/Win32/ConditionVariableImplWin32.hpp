#ifndef BULL_CORE_CONCURRENCY_WIN32_CONDITIONVARIABLEIMPLWIN32_HPP
#define BULL_CORE_CONCURRENCY_WIN32_CONDITIONVARIABLEIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Concurrency/ConditionVariableImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplWin32 : public ConditionVariableImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            ConditionVariableImplWin32();

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

            CONDITION_VARIABLE m_handler;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_WIN32_CONDITIONVARIABLEIMPLWIN32_HPP