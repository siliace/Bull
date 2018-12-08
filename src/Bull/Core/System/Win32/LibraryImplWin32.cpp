#include <Bull/Core/System/Win32/LibraryImplWin32.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplWin32::LibraryImplWin32(const String& name) :
            m_handler(LoadLibrary(name.getBuffer()))
        {
            Expect(m_handler, Throw(Win32Error, "Failed to load library " + name))
        }

        LibraryImplWin32::~LibraryImplWin32()
        {
            FreeLibrary(m_handler);
        }

        Library::LibFunction LibraryImplWin32::getFunction(const String& name) const
        {
            return reinterpret_cast<Library::LibFunction>(GetProcAddress(m_handler, name.getBuffer()));
        }
    }
}
