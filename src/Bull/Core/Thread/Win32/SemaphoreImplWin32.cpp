#include <Bull/Core/Thread/Win32/SemaphoreImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param count The initial count to set the semaphore
         *
         */
        SemaphoreImplWin32::SemaphoreImplWin32(unsigned int count)
        {
            m_handler = CreateSemaphore(nullptr, count, count, nullptr);
        }

        /*! \brief Destructor
         *
         */
        SemaphoreImplWin32::~SemaphoreImplWin32()
        {
            CloseHandle(m_handler);
        }

        /*! \brief Wait until the current thread can continue
         *
         */
        void SemaphoreImplWin32::wait()
        {
            WaitForSingleObject(m_handler, INFINITE);
        }

        /*! \brief Wait until the current thread can continue
         *
         * \param timeout The maximum time to wait before fail
         *
         * \return Return true if the waiting time was less than the timeout, false otherwise
         *
         */
        bool SemaphoreImplWin32::wait(const Time& timeout)
        {
            return WaitForSingleObject(m_handler, timeout.asMilliseconds()) == WAIT_OBJECT_0;
        }

        /*! \brief Get the current count of the semaphore
         *
         * \return Return the current count of the semaphore
         *
         */
        unsigned int SemaphoreImplWin32::getCount() const
        {
            LONG count;

            ReleaseSemaphore(m_handler, 0, &count);

            return count;
        }

        /*! \brief Release semaphore's protection
         *
         */
        void SemaphoreImplWin32::release()
        {
            ReleaseSemaphore(m_handler, 1, nullptr);
        }

        /*! \brief Get the system handler
         *
         * \return Return the native system semaphore handler
         *
         */
        SemaphoreHandler SemaphoreImplWin32::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
