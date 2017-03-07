#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/LocalImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Thread/Win32/LocalImplWin32.hpp>
    typedef Bull::prv::LocalImplWin32 LocalImplType;
#else
    #include <Bull/Core/Thread/Unix/LocalImplUnix.hpp>
    typedef Bull::prv::LocalImplUnix LocalImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific instance of LocalImpl
         *
         * \return Return the created instance
         *
         */
        LocalImpl* LocalImpl::createInstance()
        {
            return new LocalImplType();
        }

        /*! \brief Destructor
         *
         */
        LocalImpl::~LocalImpl()
        {
            /// Nothing
        }
    }
}
