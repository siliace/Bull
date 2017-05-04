#ifndef Bull_Mutex_hpp
#define Bull_Mutex_hpp

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
        friend class ConditionVariable;

    public:

        /*! \brief Default constructor
         *
         */
        Mutex();

        /*! \brief Destructor
         *
         */
        ~Mutex();

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

        std::unique_ptr<prv::MutexImpl> m_impl;
        bool m_locked;
    };
}

#endif // Bull_Mutex_hpp
