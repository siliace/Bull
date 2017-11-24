#ifndef BULL_CORE_THREAD_MUTEXIMPL_HPP
#define BULL_CORE_THREAD_MUTEXIMPL_HPP

#include <Bull/Core/Pattern/ImplPtr.hpp>
#include <Bull/Core/Thread/MutexHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class MutexImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of MutexImpl
             *
             * \return Return the created instance
             *
             */
            static ImplPtr<MutexImpl> createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~MutexImpl();

            /*! \brief Try to lock the mutex
             *
             * \return Return true if the mutex was locked successfully, false otherwise
             *
             */
            virtual bool tryLock() = 0;

            /*! \brief Lock the mutex
             *
             */
            virtual void lock() = 0;

            /*! \brief Unlock the mutex
             *
             */
            virtual void unlock() = 0;

            /*! \brief Get the mutex handler
             *
             * \return The handler
             *
             */
            virtual MutexHandler* getHandler() = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            MutexImpl() = default;
        };
    }
}

#endif // BULL_CORE_THREAD_MUTEXIMPL_HPP
