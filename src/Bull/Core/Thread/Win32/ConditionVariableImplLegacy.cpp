#include <Bull/Core/Thread/Win32/ConditionVariableImplLegacy.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        ConditionVariableImplLegacy::ConditionVariableImplLegacy()
        {

        }

        /*! \brief Destructor
         *
         */
        ConditionVariableImplLegacy::~ConditionVariableImplLegacy()
        {

        }

        /*! \brief Send a signal to a waiting thread
         *
         */
        void ConditionVariableImplLegacy::signalOne()
        {

        }

        /*! \brief Send a signal to a waiting thread
         *
         */
        void ConditionVariableImplLegacy::signalAll()
        {

        }

        /*! \brief Wait for a signal
         *
         * \param mutex The mutex to lock the resource
         *
         */
        void ConditionVariableImplLegacy::wait(Mutex& mutex)
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
        bool ConditionVariableImplLegacy::wait(Mutex& mutex, const Time& timeout)
        {
            return false;
        }
    }
}
