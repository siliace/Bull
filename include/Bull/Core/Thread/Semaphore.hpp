#ifndef Bull_Semaphore_hpp
#define Bull_Semaphore_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImpl;
    }

    class BULL_API Semaphore : public NonCopyable
    {
    public:

        /*! @brief Constructor
         *
         * @param count The initial count to set the semaphore
         *
         */
        Semaphore(unsigned int count);

        /*! @brief Destructor
         *
         */
        ~Semaphore();

        /*! @brief Wait until the current thread can continue
         *
         */
        void wait();

        /*! @brief Wait until the current thread can continue
         *
         * @param timeout The maximum time to wait before fail
         *
         * @return Return true if the waiting time was less than the timeout, false otherwise
         *
         */
        bool wait(const Time& timeout);

        /*! @brief Get the current count of the semaphore
         *
         * @return Return the current count of the semaphore
         *
         */
        unsigned int getCount() const;

        /*! @brief Release semaphore's protection
         *
         */
        void release();

    private:

        std::unique_ptr<prv::SemaphoreImpl> m_impl;
    };
}

#endif // Bull_Semaphore_hpp
