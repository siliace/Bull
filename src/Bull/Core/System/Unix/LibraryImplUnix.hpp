#ifndef Bull_LibraryImplUnix_hpp
#define Bull_LibraryImplUnix_hpp

#include <Bull/Core/System/LibraryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImplUnix : public LibraryImpl
        {
        public:

            /*! \brief Default Constructor
             *
             */
            LibraryImplUnix();

            /*! \brief Destructor
             *
             */
            ~LibraryImplUnix();

            /*! \brief Load a library
             *
             * \param name The name or the path to the library to load
             *
             * \return Return true if the library is loaded, false otherwise
             *
             */
            bool load(const String& name);

            /*! \brief Get a function from the library
             *
             * \param name The name of the function
             *
             * \return Return the function or nullptr if the function does not exists
             *
             */
            Library::LibFunction getFunction(const String& name);

        private:

            void* m_handler;
        };
    }
}

#endif // Bull_LibraryImplUnix_hpp
