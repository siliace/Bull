#include <dlfcn.h>

#include <Bull/Core/System/Unix/LibraryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default Constructor
         *
         */
        LibraryImplUnix::LibraryImplUnix() :
            m_handler(nullptr)
        {
            /// Nothing
        }

        /*! \brief Destructor
         *
         */
        LibraryImplUnix::~LibraryImplUnix()
        {
            dlclose(m_handler);
        }

        /*! \brief Load a library
         *
         * \param name The name or the path to the library to load
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        bool LibraryImplUnix::load(const String& name)
        {
            m_handler = dlopen(name, RTLD_LAZY);

            return m_handler == nullptr;
        }

        /*! \brief Get a function from the library
         *
         * \param name The name of the function
         *
         * \return Return the function or nullptr if the function does not exists
         *
         */
        Library::LibFunction LibraryImplUnix::getFunction(const String& name)
        {
            return reinterpret_cast<Library::LibFunction>(dlsym(m_handler, name));
        }
    }
}
