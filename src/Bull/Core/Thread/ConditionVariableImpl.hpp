#ifndef Bull_ConditionVariableImpl_hpp
#define Bull_ConditionVariableImpl_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of ConditionVariableImpl
             *
             * \return Return the created instance
             *
             */
            static ConditionVariableImpl* createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~ConditionVariableImpl();

            /*! \brief Send a signal to a waiting thread
             *
             */
            virtual void signalOne() = 0;

            /*! \brief Send a signal to all waiting thread
             *
             */
            virtual void signalAll() = 0;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             *
             */
            virtual void wait(Mutex& mutex) = 0;

            /*! \brief Wait for a signal
             *
             * \param mutex The mutex to lock the resource
             * \param timeout The time to wait before failing
             *
             * \return Return false if timeout, else return true
             *
             */
            virtual bool wait(Mutex& mutex, const Time& timeout) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            ConditionVariableImpl() = default;
        };
    }
}

#endif // Bull_ConditionVariableImpl_hpp

