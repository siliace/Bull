#ifndef Bull_SemaphoreImpl_hpp
#define Bull_SemaphoreImpl_hpp

#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImpl : public NonCopyable
        {
        public:

            /*! @brief Create a OS specific instance of SemaphoreImpl
             *
             * @param count The initial count to set the semaphore
             *
             * @return Return the created instance
             *
             */
            static SemaphoreImpl* createInstance(unsigned int count);

        public:

            /*! @brief Destructor
             *
             */
            virtual ~SemaphoreImpl();

            /*! @brief Wait until the current thread can continue
             *
             */
            virtual void wait() = 0;

            /*! @brief Wait until the current thread can continue
             *
             * @param timeout The maximum time to wait before fail
             *
             * @return Return true if the waiting time was less than the timeout, false otherwise
             *
             */
            virtual bool wait(const Time& timeout) = 0;

            /*! @brief Get the current count of the semaphore
             *
             * @return Return the current count of the semaphore
             *
             */
            virtual unsigned int getCount() const = 0;

            /*! @brief Release semaphore's protection
             *
             */
            virtual void release() = 0;

        protected:

            /*! @brief Default constructor
             *
             */
            SemaphoreImpl() = default;
        };
    }
}

#endif // Bull_SemaphoreImpl_hpp
