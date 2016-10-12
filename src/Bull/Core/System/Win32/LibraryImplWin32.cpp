#include <Bull/Core/System/Win32/LibraryImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Destructor
         *
         */
        LibraryImplWin32::~LibraryImplWin32()
        {
            FreeLibrary(m_handler);
        }

        /*! \brief Load a library
         *
         * \param name The name or the path to the library to load
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        bool LibraryImplWin32::load(const String& name)
        {
            m_handler = LoadLibrary(name);

            return m_handler != nullptr;
        }

        /*! \brief Get a function from the library
         *
         * \param name The name of the function
         *
         * \return Return the function or nullptr if the function does not exists
         *
         */
        Library::LibFunction LibraryImplWin32::getFunction(const String& name)
        {
            return reinterpret_cast<Library::LibFunction>(GetProcAddress(m_handler, name));
        }
    }
}
