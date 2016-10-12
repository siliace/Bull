#include <Bull/Core/Thread/Win32/ConditionVariableImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        ConditionVariableImplWin32::ConditionVariableImplWin32()
        {
            InitializeConditionVariable(&m_handler);
        }

        /*! \brief Send a signal to a waiting thread
         *
         */
        void ConditionVariableImplWin32::signalOne()
        {
            WakeConditionVariable(&m_handler);
        }

        /*! \brief Send a signal to a waiting thread
         *
         */
        void ConditionVariableImplWin32::signalAll()
        {
            WakeAllConditionVariable(&m_handler);
        }

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to lock the resource
         *
         */
        void ConditionVariableImplWin32::wait(Mutex& mutex)
        {

        }

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to lock the resource
         * \param timeout The time to wait before failing
         *
         * \return Return false if timeout, else return true
         *
         */
        bool ConditionVariableImplWin32::wait(Mutex& mutex, const Time& timeout)
        {
            return false;
        }
    }
}
