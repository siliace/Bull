#include <Bull/Core/System/Win32/LibraryImplWin32.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplWin32::LibraryImplWin32(const std::string& name) :
                m_handler(LoadLibrary(name.c_str()))
        {
            Expect(m_handler, Throw(Win32Error, "Failed to load library " + name))
        }

        LibraryImplWin32::~LibraryImplWin32()
        {
            FreeLibrary(m_handler);
        }

        void* LibraryImplWin32::getSymbolPointer(const std::string& name) const
        {
            return reinterpret_cast<void*>(GetProcAddress(m_handler, name.c_str()));
        }
    }
}
