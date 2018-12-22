#ifndef BULL_CORE_SYSTEM_WIN32_LIBRARYIMPLWIN32_HPP
#define BULL_CORE_SYSTEM_WIN32_LIBRARYIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/System/LibraryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImplWin32 : public LibraryImpl
        {
        public:

            /*! \brief Constructor
             *
             * \param name The name or the path to the library to load
             *
             */
            explicit LibraryImplWin32(const String& name);

            /*! \brief Destructor
             *
             */
            ~LibraryImplWin32();

            /*! \brief Get a function from the library
             *
             * \param name The name of the function
             *
             * \return Return the function or nullptr if the function does not exists
             *
             */
            void* getSymbolPointer(const String& name) const override;

        private:

            HMODULE m_handler;
        };
    }
}

#endif // BULL_CORE_SYSTEM_WIN32_LIBRARYIMPLWIN32_HPP
