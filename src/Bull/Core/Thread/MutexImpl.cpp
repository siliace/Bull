#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/MutexImplWin32.hpp>
    typedef Bull::prv::MutexImplWin32 MutexImplType;
#else
    #include <Bull/Core/Thread/Unix/MutexImplUnix.hpp>
    typedef Bull::prv::MutexImplUnix MutexImplType;
#endif

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific instance of MutexImpl
         *
         * \return Return the created instance
         *
         */
        MutexImpl* MutexImpl::createInstance()
        {
            return new MutexImplType();
        }

        /*! \brief Destructor
         *
         */
        MutexImpl::~MutexImpl()
        {
            /// Nothing
        }
    }
}
