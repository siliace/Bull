#ifndef Bull_ThreadImpl_hpp
#define Bull_ThreadImpl_hpp

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Time/Time.hpp>

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
            static ThreadImpl* createInstance(Functor<void>& function, Thread::Priority priority);

            /*! \brief Asleep the current thread
             *
             * \param time The time to sleep
             *
             */
            static void sleep(const Time& time);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~ThreadImpl();

            /*! \brief Wait the end of a thread
             *
             */
            virtual void wait() = 0;

            /*! \brief Stop the thread
             *
             */
            virtual void stop() = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            ThreadImpl() = default;
        };
    }
}

#endif // Bull_ThreadImpl_hpp
