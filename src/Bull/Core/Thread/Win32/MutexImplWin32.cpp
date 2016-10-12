#include <Bull/Core/Thread/Win32/MutexImplWin32.hpp>

namespace Bull
{
    namespace prv
    {

        /*! \brief Default constructor
         *
         */
        MutexImplWin32::MutexImplWin32()
        {
            InitializeCriticalSection(&m_handler);
        }

        /*! \brief Destructor
         *
         */
        MutexImplWin32::~MutexImplWin32()
        {
            DeleteCriticalSection(&m_handler);
        }

        /*! \brief Try to lock the mutex
         *
         * \return Return true if the mutex was locked successfully, else return false
         *
         */
        bool MutexImplWin32::tryLock()
        {
            return TryEnterCriticalSection(&m_handler);
        }

        /*! \brief Lock the mutex
         *
         */
        void MutexImplWin32::lock()
        {
            EnterCriticalSection(&m_handler);
        }

        /*! \brief Unlock the mutex
         *
         */
        void MutexImplWin32::unlock()
        {
            LeaveCriticalSection(&m_handler);
        }

        /*! \brief Get the native handler
         *
         * \return Return the mutex native handler
         *
         */
        MutexHandler MutexImplWin32::getSystemHandler() const
        {
            return m_handler;
        }

        MutexHandler* MutexImplWin32::getHandlerPointer()
        {
            return &m_handler;
        }
    }
}
