#ifndef BULL_CORE_CONCURRENCY_WIN32_SEMAPHOREIMPLWIN32_HPP
#define BULL_CORE_CONCURRENCY_WIN32_SEMAPHOREIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Concurrency/SemaphoreImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImplWin32 : public SemaphoreImpl
        {
        private:

            static constexpr LONG MaxSemaphoreCount = 32 * 1024;

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
            bool wait(const Duration& timeout) override;

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

            LONG   m_count;   /*!< The current count value of the semaphore. We keep our own counter to avoid a dummy call to ReleaseSemaphore */
            HANDLE m_handler; /*!< The handler of the semaphore */
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_WIN32_SEMAPHOREIMPLWIN32_HPP
