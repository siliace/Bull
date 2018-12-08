#ifndef BULL_CORE_SYSTEM_LIBRARYIMPL_HPP
#define BULL_CORE_SYSTEM_LIBRARYIMPL_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Library.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of LibraryImpl
             *
             * \param name The name or the path to the library to load
             *
             * \return The created instance
             *
             */
            static std::unique_ptr<LibraryImpl> createInstance(const String& name);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~LibraryImpl();

            /*! \brief Get a function from the library
             *
             * \param name The name of the function
             *
             * \return The function or nullptr if the function does not exists
             *
             */
            virtual Library::LibFunction getFunction(const String& name) const = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            LibraryImpl() = default;
        };
    }
}

#endif // BULL_CORE_SYSTEM_LIBRARYIMPL_HPP
