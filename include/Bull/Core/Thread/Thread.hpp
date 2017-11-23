#ifndef BULL_CORE_THREAD_THREAD_HPP
#define BULL_CORE_THREAD_THREAD_HPP

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/ImplPtr.hpp>
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
         * \param function The function to run
         * \param priority The priority of the thread (by default inherit form the parent thread)
         *
         */
        explicit Thread(const Functor<void>& function, ThreadPriority priority = ThreadPriority_Idle);

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

        ImplPtr<prv::ThreadImpl> m_impl;
        Functor<void>            m_function;
        ThreadPriority           m_priority;
    };
}

#endif // BULL_CORE_THREAD_THREAD_HPP
