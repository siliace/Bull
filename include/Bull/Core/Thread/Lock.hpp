#ifndef BULL_CORE_THREAD_LOCK_HPP
#define BULL_CORE_THREAD_LOCK_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    class BULL_CORE_API Lock : public NonCopyable
    {
    public:

        /*! \brief Constructor
         *
         * Lock the mutex
         *
         * \param mutex The mutex to lock
         *
         */
        Lock(Mutex& mutex);

        /*! \brief Destructor
         *
         * Unlock the mutex
         *
         */
        virtual ~Lock();

    private:

        Mutex& m_mutex;
    };
}

#endif // BULL_CORE_THREAD_LOCK_HPP
