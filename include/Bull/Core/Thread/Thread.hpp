#ifndef BULL_CORE_THREAD_THREAD_HPP
#define BULL_CORE_THREAD_THREAD_HPP

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ThreadImpl;
    }

    class BULL_CORE_API Thread : public NonCopyable
    {
    public:

        enum Priority
        {
            Idle        = 0, /*!< Scheduled only when no other threads are running */
            Lowest      = 1, /*!< Scheduled less often than LowPriority */
            Low         = 2, /*!< Scheduled less often than NormalPriority */
            Normal      = 3, /*!< The default priority of the operating system */
            High        = 4, /*!< Scheduled more often than NormalPriority */
            Highest     = 5, /*!< Scheduled more often than HighPriority */
            TimeCritial = 6, /*!< Scheduled as often as possible */
            Inherit     = 7  /*!< Use the same priority as the creating thread */
        };

        /*! \brief Asleep the current thread
         *
         * \param time The time to sleep (in microseconds)
         *
         */
        static void sleep(const Time& time);

    public:

        /*! \brief Default constructor
         *
         */
        Thread();

        /*! \brief Constructor
         *
         * \param function The function to store
         *
         */
        template<typename Function>
        Thread(Function function);

        /*! \brief Constructor
         *
         * \param function The function to store
         * \param args     Arguments of the function
         *
         */
        template<typename Function, typename... Args>
        Thread(Function function, Args... args);

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param member   The method of the instance to store
         *
         */
        template<typename Instance, typename Class>
        Thread(Instance& instance, void(Class::*member)());

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param member   The method of the instance to store
         *
         */
        template<typename Instance, typename Class>
        Thread(const Instance& instance, void(Class::*member)() const);

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param member   The method of the instance to store
         * \param args     Arguments of the function
         *
         */
        template<typename Instance, typename Class, typename... Args>
        Thread(Instance& instance, void(Class::*member)(Args...), Args... args);

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param member   The method of the instance to store
         * \param args     Arguments of the function
         *
         */
        template<typename Instance, typename Class, typename... Args>
        Thread(const Instance& instance, void(Class::*member)(Args...) const, Args... args);

        /*! \brief Constructor
         *
         * \param function The function to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
        explicit Thread(const Functor<void>& function, Priority priority = Priority::Inherit);

        /*! \brief Destructor
         *
         */
        ~Thread();

        /*! \brief Start the thread
         *
         * \return Return true if the thread is started successfully, else return false
         *
         */
        bool start();

        /*! \brief Check if a thread is running
         *
         * \return Return true if the thread is running, else return false
         *
         */
        bool isRunning() const;

        /*! \brief Wait the end of a thread
         *
         */
        void wait();

        /*! \brief Stop the thread
         *
         */
        void stop();

        /*! \brief Get the priority of the thread
         *
         * \return The thread priority
         *
         */
        Thread::Priority getPriority() const;

    private:

        /*! \brief Reset the implementation
         *
         */
        void reset();

        /// We do not use std::unique_ptr because
        /// in Thread.inl, prv::ThreadImpl
        /// would be an incomplete type
        prv::ThreadImpl* m_impl;
        Functor<void>    m_function;
        Thread::Priority m_priority;
    };
}

#include <Bull/Core/Thread/Thread.inl>

#endif // BULL_CORE_THREAD_THREAD_HPP
