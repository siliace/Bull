#ifndef Bull_ConditionVariableImplWin32_hpp
#define Bull_ConditionVariableImplWin32_hpp

#include <Bull/Core/System/Config.hpp>
#include <windows.h>

#include <Bull/Core/Thread/ConditionVariableImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplWin32 : public ConditionVariableImpl
        {
        public:

            /*! @brief Default constructor
             *
             */
            ConditionVariableImplWin32();

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
             * @param mutex The mutex to lock the resource
             *
             */
            void wait(MutexImpl* mutex) override;

            /*! @brief Wait for a signal
             *
             * @param mutex The mutex to lock the resource
             * @param timeout The time to wait before failing
             *
             * @return Return false if timeout, else return true
             *
             */
            bool wait(MutexImpl* mutex, const Time& timeout) override;

        private:

            CONDITION_VARIABLE m_handler;
        };
    }
}

#endif // Bull_ConditionVariableImplWin32_hpp
