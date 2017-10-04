#include <Bull/Core/System/Win32/LibraryImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplWin32::~LibraryImplWin32()
        {
            FreeLibrary(m_handler);
        }

        bool LibraryImplWin32::load(const String& name)
        {
            m_handler = LoadLibrary(name.getBuffer());

            return m_handler != nullptr;
        }

        Library::LibFunction LibraryImplWin32::getFunction(const String& name)
        {
            return reinterpret_cast<Library::LibFunction>(GetProcAddress(m_handler, name.getBuffer()));
        }
    }
}
