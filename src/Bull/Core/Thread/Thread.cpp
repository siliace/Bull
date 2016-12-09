#include <Bull/Core/Thread/Thread.hpp>
#include <Bull/Core/Thread/ThreadImpl.hpp>

namespace Bull
{
    /*! \brief Asleep the current thread
     *
     * \param time The time to sleep (in microseconds)
     *
     */
    void Thread::sleep(const Time& time)
    {
        prv::ThreadImpl::sleep(time);
    }

    Thread::Thread() :
        m_impl(nullptr),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param function The function to run
     * \param priority The priority of the thread (by default inherit form the parent thread)
     *
     */
    Thread::Thread(const Functor<void>& function, Priority priority) :
        m_impl(nullptr),
        m_function(function),
        m_priority(priority)
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    Thread::~Thread()
    {
        wait();
    }

    /*! \brief Start the thread
     *
     * \return Return true if the thread is started successfully, else return false
     *
     */
    bool Thread::start()
    {
        if(isRunning())
        {
            return false;
        }

        m_impl = prv::ThreadImpl::createInstance(m_function, m_priority);

        return true;
    }

    /*! \brief Check if a thread is running
     *
     * \return Return true if the thread is running, else return false
     *
     */
    bool Thread::isRunning() const
    {
        return m_impl != nullptr;
    }

    /*! \brief Wait the end of a thread
     *
     */
    void Thread::wait()
    {
        if(m_impl)
        {
            m_impl->wait();
            delete m_impl;
            m_impl = nullptr;
        }
    }

    /*! \brief Stop the thread
     *
     */
    void Thread::stop()
    {
        if(m_impl)
        {
            m_impl->stop();
            delete m_impl;
            m_impl = nullptr;
        }
    }

    /*! \brief Get the priority of the thread
     *
     * \return The thread priority
     *
     */
    Thread::Priority Thread::getPriority() const
    {
        return m_priority;
    }
}
