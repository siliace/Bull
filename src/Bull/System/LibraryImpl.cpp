#include <Bull/System/LibraryImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/System/Win32/LibraryImplWin32.hpp>
    typedef Bull::prv::LibraryImplWin32 LibraryImplType;
#else
    #include <Bull/System/Unix/LibraryImplUnix.hpp>
    typedef Bull::prv::LibraryImplUnix LibraryImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
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

        LibraryImpl::~LibraryImpl() = default;
    }
}