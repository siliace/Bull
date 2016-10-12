#ifndef Bull_MutexImplWin32_hpp
#define Bull_MutexImplWin32_hpp

#include <windows.h>

#include <Bull/Core/Thread/MutexImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class MutexImplWin32 : public MutexImpl
        {
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

            /*! \brief Get the native handler
             *
             * \return Return the mutex native handler
             *
             */
            MutexHandler getSystemHandler() const override;

        protected:

            /*! \brief Get a pointer to the handler
             *
             * Used only by ConditionalVariableImplWin32
             *
             * \return Return a pointer to the system handler
             * \see ConditionalVariableImplWin32
             */
            MutexHandler* getHandlerPointer() override;

        private:

            CRITICAL_SECTION m_handler;
        };
    }
}

#endif // Bull_MutexImplWin32_hpp
