#ifndef Bull_ConditionVariableImplLegacy_hpp
#define Bull_ConditionVariableImplLegacy_hpp

#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplLegacy : public ConditionVariableImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            ConditionVariableImplLegacy();

            /*! \brief Destructor
             *
             */
            ~ConditionVariableImplLegacy();

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
            void wait(Mutex& mutex) override;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             * \param timeout The time to wait before failing
             *
             * \return Return false if timeout, else return true
             *
             */
            bool wait(Mutex& mutex, const Time& timeout) override;
        };
    }
}

#endif // Bull_ConditionVariableImplLegacy_hpp
