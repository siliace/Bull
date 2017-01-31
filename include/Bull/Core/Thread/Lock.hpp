#ifndef Bull_Lock_hpp
#define Bull_Lock_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    class BULL_API Lock : public NonCopyable
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
        ~Lock();

    private:

        Mutex& m_mutex;
    };
}

#endif // Bull_Lock_hpp
