#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/SemaphoreImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/SemaphoreImplWin32.hpp>
    typedef Bull::prv::SemaphoreImplWin32 SemaphoreImplType;
#else
    #include <Bull/Core/Thread/Unix/SemaphoreImplUnix.hpp>
    typedef Bull::prv::SemaphoreImplUnix SemaphoreImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific instance of SemaphoreImpl
         *
         * \param count The initial count to set the semaphore
         *
         * \return Return the created instance
         *
         */
        SemaphoreImpl* SemaphoreImpl::createInstance(unsigned int count)
        {
            return new SemaphoreImplType(count);
        }

        /*! \brief Destructor
         *
         */
        SemaphoreImpl::~SemaphoreImpl()
        {
            /// Nothing
        }
    }
}
