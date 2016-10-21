#ifndef Bull_SemaphoreImplUnix_hpp
#define Bull_SemaphoreImplUnix_hpp

#include <semaphore.h>

#include <Bull/Core/Thread/SemaphoreImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImplUnix : public SemaphoreImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            SemaphoreImplUnix() = delete;

            /*! \brief Constructor
             *
             * \param count The initial count to set the semaphore
             *
             */
            SemaphoreImplUnix(unsigned int count);

            /*! \brief Destructor
             *
             */
            ~SemaphoreImplUnix();

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

            /*! \brief Get the system handler
             *
             * \return Return the native system semaphore handler
             *
             */
            SemaphoreHandler getSystemHandler() const;


        private:

            sem_t m_handler;
        };
    }
}

#endif // Bull_SemaphoreImplUnix_hpp
