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
        ImplPtr<LibraryImpl> LibraryImpl::createInstance(const String& name)
        {
            ImplPtr<LibraryImpl> ptr = ImplPtr<LibraryImpl>::make<LibraryImplType>();
            ptr->load(name);

            return ptr;
        }

        LibraryImpl::~LibraryImpl() = default;
    }
}
