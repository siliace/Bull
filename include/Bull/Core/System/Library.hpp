#ifndef BULL_CORE_SYSTEM_LIBRARY_HPP
#define BULL_CORE_SYSTEM_LIBRARY_HPP

#include <memory>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Core/Export.hpp>

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

        /*! \brief Destructor
         *
         */
        ~Library();

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

        std::unique_ptr<prv::LibraryImpl> m_impl;
    };
}

#endif // BULL_CORE_SYSTEM_LIBRARY_HPP
