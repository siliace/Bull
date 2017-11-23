#ifndef BULL_CORE_SYSTEM_LIBRARY_HPP
#define BULL_CORE_SYSTEM_LIBRARY_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/ImplPtr.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImpl;
    }

    class BULL_CORE_API Library : public NonCopyable
    {
    public:

        using LibFunction = int(*)();

    public:

        /*! \brief Default constructor
         *
         */
        Library() = default;

        /*! \brief Constructor
         *
         * \param name The name or the path to the library to load
         *
         */
        explicit Library(const String& name);

        /*! \brief Constructor by movement
         *
         * \param library The Library to move
         *
         */
        Library(Library&& library) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~Library();

        /*! \brief Basic assignment operator by movement
         *
         * \param library The Library to move
         *
         * \return This
         *
         */
        Library& operator=(Library&& library) noexcept = default;

        /*! \brief Load a library
         *
         * \param name The name or the path to the library to load
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        bool load(const String& name);

        /*! \brief Check whether the library is loaded
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        bool isLoaded() const;

        /*! \brief Get a function from the library
         *
         * \param name The name of the function
         *
         * \return Return the function or nullptr if the function does not exists
         *
         */
        LibFunction getFunction(const String& name);

        /*! \brief Free the library
         *
         */
        void free();

    private:

        ImplPtr<prv::LibraryImpl> m_impl;
    };
}

#endif // BULL_CORE_SYSTEM_LIBRARY_HPP
