#ifndef BULL_CORE_CONCURRENCY_THREAD_HPP
#define BULL_CORE_CONCURRENCY_THREAD_HPP

#include <functional>
#include <memory>

#include <Bull/Core/Concurrency/Runnable.hpp>
#include <Bull/Core/Concurrency/ThreadPriority.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    namespace prv
    {
        class ThreadImpl;
    }

    class BULL_CORE_API Thread : public NonCopyable
    {
    public:

        using Callable = std::function<void()>;

        /*! \brief Asleep the current thread
         *
         * \param time The time to sleep (in microseconds)
         *
         */
        static void sleep(const Duration& time);

    private:

        class FunctionRunnable : public Runnable
        {
        public:

            explicit FunctionRunnable(std::function<void()> function) :
                m_function(function)
            {
                /// Nothing
            }

            void run() override
            {
                m_function();
            }

        private:

            std::function<void()> m_function;
        };

    public:

        /*! \brief Default constructor
         *
         */
        Thread();

        /*! \brief Constructor
         *
         * \param runnable The object to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
        explicit Thread(Runnable* runnable, ThreadPriority priority = ThreadPriority_Inherit);

        /*! \brief Constructor
         *
         * \param callable The function to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
        explicit Thread(const Callable& callable, ThreadPriority priority = ThreadPriority_Inherit);

        /*! \brief Constructor by movement
         *
         * \param thread The Thread to move
         *
         */
        Thread(Thread&& thread) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~Thread();

        /*! \brief Basic assignment operator by movement
         *
         * \param thread The Thread to move
         *
         * \return This
         *
         */
        Thread& operator=(Thread&& thread) noexcept = default;

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

        /*! \brief Terminate the Thread
         *
         */
        void terminate();

        /*! \brief Get the runnable used by the Thread
         *
         * \return The runnable
         *
         */
        Runnable* getRunnable() const;

        /*! \brief Get the priority of the thread
         *
         * \return The thread priority
         *
         */
        ThreadPriority getPriority() const;

    private:

        std::unique_ptr<prv::ThreadImpl> m_impl;
        std::unique_ptr<Runnable>        m_runnable;
        ThreadPriority                   m_priority;
    };
}

#endif // BULL_CORE_CONCURRENCY_THREAD_HPP
