#ifndef BULL_CORE_SYSTEM_UNIX_LIBRARYIMPLUNIX_HPP
#define BULL_CORE_SYSTEM_UNIX_LIBRARYIMPLUNIX_HPP

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
            explicit LibraryImplUnix(const String& name);

            /*! \brief Destructor
             *
             */
            ~LibraryImplUnix();

            /*! \brief Get a function from the library
             *
             * \param name The name of the function
             *
             * \return The function or nullptr if the function does not exists
             *
             */
            void* getSymbolPointer(const String& name) const override;

        private:

            void* m_handler;
        };
    }
}

#endif // BULL_CORE_SYSTEM_UNIX_LIBRARYIMPLUNIX_HPP
