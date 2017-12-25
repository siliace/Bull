#ifndef BULL_CORE_THREAD_THREAD_HPP
#define BULL_CORE_THREAD_THREAD_HPP

#include <functional>
#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Runnable.hpp>
#include <Bull/Core/Thread/ThreadPriority.hpp>
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
        template <typename T, typename = std::enable_if<std::is_base_of<Runnable, T>::value>>
        explicit Thread(T* runnable, ThreadPriority priority = ThreadPriority_Inherit) :
            Thread(std::bind(&T::run, runnable), priority)
        {
            /// Nothing
        }

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

        /*! \brief Get the priority of the thread
         *
         * \return The thread priority
         *
         */
        ThreadPriority getPriority() const;

    private:

        std::unique_ptr<prv::ThreadImpl> m_impl;
        std::function<void()>    m_function;
        ThreadPriority           m_priority;
    };
}

#endif // BULL_CORE_THREAD_THREAD_HPP
