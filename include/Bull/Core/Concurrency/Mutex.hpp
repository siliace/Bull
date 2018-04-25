#ifndef BULL_CORE_CONCURRENCY_MUTEX_HPP
#define BULL_CORE_CONCURRENCY_MUTEX_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class ConditionVariable;

    namespace prv
    {
        class MutexImpl;
    }

    class BULL_CORE_API Mutex : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Mutex();

        /*! \brief Constructor by movement
         *
         * \param mutex The Mutex to move
         *
         */
        Mutex(Mutex&& mutex) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~Mutex();

        /*! \brief Basic assignment operator by movement
         *
         * \param mutex The Mutex to move
         *
         * \return This
         *
         */
        Mutex& operator=(Mutex&& mutex) noexcept = default;

        /*! \brief Try to lock the mutex
         *
         * \return Return true if the mutex was locked successfully, else return false
         *
         */
        bool tryLock();

        /*! \brief Lock the mutex
         *
         */
        void lock();

        /*! \brief Check whether the mutex is locked
         *
         * \return Return true if the mutex is locked, false otherwise
         *
         */
        bool isLocked() const;

        /*! \brief Unlock the mutex
         *
         */
        void unlock();

    private:

        friend class ConditionVariable;

        std::unique_ptr<prv::MutexImpl> m_impl;
        bool                            m_locked;
    };
}

#endif // BULL_CORE_CONCURRENCY_MUTEX_HPP
