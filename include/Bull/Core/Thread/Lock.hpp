#ifndef Bull_Lock_hpp
#define Bull_Lock_hpp

#include <Bull/Core/Exception.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    class BULL_API Lock : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Lock() = delete;

        /*! Constructor
         *
         * Lock the mutex
         *
         * \param mutex The mutex to lock
         *
         */
        Lock(Mutex& mutex);

        /*! Destructor
         *
         * Unlock the mutex
         *
         */
        ~Lock();

    private:

        Mutex& m_mutex;

        DeclarePublicException(FailToLockMutex, "The mutex could not be locked");
    };
}

#endif // Bull_Lock_hpp
