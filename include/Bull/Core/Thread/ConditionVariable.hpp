#ifndef Bull_ConditionVariable_hpp
#define Bull_ConditionVariable_hpp

#include <memory>

#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ConditionVariableImpl;
    }

    class BULL_API ConditionVariable : public NonCopyable
    {
    public:

        /*! @brief Default constructor
         *
         */
        ConditionVariable();

        /*! @brief Destructor
         *
         */
        ~ConditionVariable();

        /*! @brief Send a signal to a waiting thread
         *
         */
        void signalOne();

        /*! @brief Send a signal to all waiting thread
         *
         */
        void signalAll();

        /*! @brief Wait for a signal
         *
         * @param mutex The mutex to lock the resource
         *
         */
        void wait(Mutex& mutex);

        /*! @brief Wait for a signal
         *
         * @param mutex The mutex to lock the resource
         * @param timeout The time to wait before failing
         *
         * @return Return false if timeout, else return true
         *
         */
        bool wait(Mutex& mutex, const Time& timeout);

    private:

        std::unique_ptr<prv::ConditionVariableImpl> m_impl;
    };
}

#endif // Bull_ConditionVariable_hpp
