#ifndef BULL_CORE_THREAD_THREAD_HPP
#define BULL_CORE_THREAD_THREAD_HPP

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/ThreadPriority.hpp>
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
        explicit Thread(Function function);

        /*! \brief Constructor
         *
         * \param function The function to store
         * \param args     Arguments of the function
         *
         */
        template<typename Function, typename... Args>
        explicit Thread(Function function, Args... args);

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
        explicit Thread(const Functor<void>& function, ThreadPriority priority = ThreadPriority_Idle);

        /*! \brief Destructor
         *
         */
        virtual ~Thread();

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
        ThreadPriority getPriority() const;

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
        ThreadPriority   m_priority;
    };
}

#include <Bull/Core/Thread/Thread.inl>

#endif // BULL_CORE_THREAD_THREAD_HPP
