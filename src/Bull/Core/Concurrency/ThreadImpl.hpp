#ifndef BULL_CORE_CONCURRENCY_THREADIMPL_HPP
#define BULL_CORE_CONCURRENCY_THREADIMPL_HPP

#include <functional>
#include <memory>

#include <Bull/Core/Concurrency/Runnable.hpp>
#include <Bull/Core/Concurrency/ThreadPriority.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    namespace prv
    {
        class ThreadImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of ThreadImpl
             *
             * \param function The function to run in the thread
             * \param priority The priority of the thread
             *
             * \return Return the created instance
             *
             */
            static std::unique_ptr<ThreadImpl> createInstance(Runnable* function, ThreadPriority priority);

            /*! \brief Asleep the current thread
             *
             * \param time The time to sleep
             *
             */
            static void sleep(const Duration& time);

            /*! \brief Set the name of the current thread
             *
             * \param name The name of the thread
             *
             */
            static void setCurrentName(const String& name);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~ThreadImpl();

            virtual bool isRunning() const = 0;

            virtual void wait() = 0;

            virtual void terminate() = 0;

            /*! \brief Set the name of the thread
             *
             * \param name The name
             *
             */
            virtual void setName(const String& name) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            ThreadImpl() = default;
        };
    }
}

#endif // BULL_CORE_CONCURRENCY_THREADIMPL_HPP
