#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/System/LibraryImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/System/Win32/LibraryImplWin32.hpp>
    typedef Bull::prv::LibraryImplWin32 LibraryImplType;
#else
    #include <Bull/Core/System/Unix/LibraryImplUnix.hpp>
    typedef Bull::prv::LibraryImplUnix LibraryImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific instance of LibraryImpl
         *
         * \param name The name or the path to the library to load
         *
         * \return Return the created instance
         *
         */
        LibraryImpl* LibraryImpl::createInstance(const String& name)
        {
            LibraryImpl* instance = new LibraryImplType();

            if(instance->load(name))
            {
                return instance;
            }

            delete instance;

            return nullptr;
        }

        /*! \brief Destructor
         *
         */
        LibraryImpl::~LibraryImpl()
        {
            /// Nothing
        }
    }
}
