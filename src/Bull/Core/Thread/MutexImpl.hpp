#ifndef Bull_MutexImpl_hpp
#define Bull_MutexImpl_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
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
            static MutexImpl* createInstance();

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

            /*! \brief Get the native handler
             *
             * \return Return the mutex native handler
             *
             */
            virtual MutexHandler getSystemHandler() const = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            MutexImpl() = default;
        };
    }
}

#endif // Bull_MutexImpl_hpp
