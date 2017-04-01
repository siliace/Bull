#ifndef Bull_MutexImplWin32_hpp
#define Bull_MutexImplWin32_hpp

#include <windows.h>

#include <Bull/Core/Thread/MutexImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplWin32;

        class MutexImplWin32 : public MutexImpl
        {
            friend class ConditionVariableImplWin32;

        public:

            /*! @brief Default constructor
             *
             */
            MutexImplWin32();

            /*! @brief Destructor
             *
             */
            ~MutexImplWin32();

            /*! @brief Try to lock the mutex
             *
             * @return Return true if the mutex was locked successfully, else return false
             *
             */
            bool tryLock() override;

            /*! @brief Lock the mutex
             *
             */
            void lock() override;

            /*! @brief Unlock the mutex
             *
             */
            void unlock() override;

        private:

            CRITICAL_SECTION m_handler;
        };
    }
}

#endif // Bull_MutexImplWin32_hpp
