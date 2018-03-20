#include <Bull/Core/System/Win32/LibraryImplWin32.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplWin32::LibraryImplWin32() :
            m_handler(nullptr)
        {
            /// Nothing
        }

        LibraryImplWin32::~LibraryImplWin32()
        {
            if(isLoaded())
            {
                FreeLibrary(m_handler);
            }
        }

        bool LibraryImplWin32::load(const String& name)
        {
            return (m_handler = LoadLibrary(name.getBuffer())) != nullptr;
        }

        bool LibraryImplWin32::isLoaded() const
        {
            return m_handler != nullptr;
        }

        Library::LibFunction LibraryImplWin32::getFunction(const String& name)
        {
            if(isLoaded())
            {
                return reinterpret_cast<Library::LibFunction>(GetProcAddress(m_handler, name.getBuffer()));
            }

            return nullptr;
        }
    }
}
