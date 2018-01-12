#ifndef BULL_CORE_CONCURRENCY_WIN32_MUTEXIMPLWIN32_HPP
#define BULL_CORE_CONCURRENCY_WIN32_MUTEXIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Concurrency/MutexImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImplWin32;

        class MutexImplWin32 : public MutexImpl
        {
            friend class ConditionVariableImplWin32;

        public:

            /*! \brief Default constructor
             *
             */
            MutexImplWin32();

            /*! \brief Destructor
             *
             */
            ~MutexImplWin32();

            /*! \brief Try to lock the mutex
             *
             * \return Return true if the mutex was locked successfully, else return false
             *
             */
            bool tryLock() override;

            /*! \brief Lock the mutex
             *
             */
            void lock() override;

            /*! \brief Unlock the mutex
             *
             */
            void unlock() override;

            /*! \brief Get the mutex handler
             *
             * \return The handler
             *
             */
            MutexHandler* getHandler() override;

        private:

            CRITICAL_SECTION m_handler;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_WIN32_MUTEXIMPLWIN32_HPP