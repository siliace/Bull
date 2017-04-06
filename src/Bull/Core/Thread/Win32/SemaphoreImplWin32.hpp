#ifndef Bull_SemaphoreImplWin32_hpp
#define Bull_SemaphoreImplWin32_hpp

#include <windows.h>

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
            SemaphoreImplWin32(unsigned int count);

            /*! \brief Destructor
             *
             */
            ~SemaphoreImplWin32();

            /*! \brief Wait until the current thread can continue
             *
             */
            void wait();

            /*! \brief Wait until the current thread can continue
             *
             * \param timeout The maximum time to wait before fail
             *
             * \return Return true if the waiting time was less than the timeout, false otherwise
             *
             */
            bool wait(const Time& timeout);

            /*! \brief Get the current count of the semaphore
             *
             * \return Return the current count of the semaphore
             *
             */
            unsigned int getCount() const;

            /*! \brief Release semaphore's protection
             *
             */
            void release();

        private:

            HANDLE m_handler;
        };
    }
}

#endif // Bull_SemaphoreImplWin32_hpp
