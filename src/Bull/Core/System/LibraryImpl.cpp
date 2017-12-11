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
        std::unique_ptr<LibraryImpl> LibraryImpl::createInstance(const String& name)
        {
            std::unique_ptr<LibraryImpl> ptr = std::make_unique<LibraryImplType>();
            ptr->load(name);

            return ptr;
        }

        LibraryImpl::~LibraryImpl() = default;
    }
}
