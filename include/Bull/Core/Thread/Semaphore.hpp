#ifndef Bull_Semaphore_hpp
#define Bull_Semaphore_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/SemaphoreHandler.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class SemaphoreImpl;
    }

    class Semaphore : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Semaphore() = delete;

        /*! \brief Constructor
         *
         * \param count The initial count to set the semaphore
         *
         */
        Semaphore(unsigned int count);

        /*! \brief Destructor
         *
         */
        ~Semaphore();

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

        std::unique_ptr<prv::SemaphoreImpl> m_impl;
    };
}

#endif // Bull_Semaphore_hpp
