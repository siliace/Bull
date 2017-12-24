#ifndef BULL_CORE_THREAD_WIN32_SEMAPHOREIMPLWIN32_HPP
#define BULL_CORE_THREAD_WIN32_SEMAPHOREIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Thread/SemaphoreImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImplWin32 : public SemaphoreImpl
        {
        public:

            /*! \brief Constructor
             *
             * \param count The initial count to set the semaphore
             *
             */
            explicit SemaphoreImplWin32(unsigned int count);

            /*! \brief Destructor
             *
             */
            ~SemaphoreImplWin32();

            /*! \brief Wait until the current thread can continue
             *
             */
            void wait() override;

            /*! \brief Wait until the current thread can continue
             *
             * \param timeout The maximum time to wait before fail
             *
             * \return Return true if the waiting time was less than the timeout, false otherwise
             *
             */
            bool wait(const Time& timeout) override;

            /*! \brief Get the current count of the semaphore
             *
             * \return Return the current count of the semaphore
             *
             */
            unsigned int getCount() const override;

            /*! \brief Release semaphore's protection
             *
             */
            void release() override;

        private:

            HANDLE m_handler;
        };
    }
}

#endif // BULL_CORE_THREAD_WIN32_SEMAPHOREIMPLWIN32_HPP
