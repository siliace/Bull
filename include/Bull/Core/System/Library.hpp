#ifndef BULL_CORE_SYSTEM_LIBRARY_HPP
#define BULL_CORE_SYSTEM_LIBRARY_HPP

#include <functional>
#include <memory>

#include <string>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImpl;
    }

    class BULL_CORE_API Library : public NonCopyable
    {
    public:

        /** \brief Default constructor
         *
         */
        Library() = default;

        /** \brief Constructor
         *
         * \param name The name or the path to the library to load
         *
         */
        explicit Library(const std::string& name);

        /** \brief Constructor by movement
         *
         * \param library The Library to move
         *
         */
        Library(Library&& library) noexcept = default;

        /** \brief Destructor
         *
         */
        ~Library();

        /** \brief Basic assignment operator by movement
         *
         * \param library The Library to move
         *
         * \return This
         *
         */
        Library& operator=(Library&& library) noexcept = default;

        /** \brief Load a library
         *
         * \param name The name or the path to the library to load
         *
         */
        void load(const std::string& name);

        /** \brief Check whether the library is loaded
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        bool isLoaded() const;

        /** \brief Get a function from the library
         *
         * \param name The name of the function
         *
         * \return Return the function or nullptr if the function does not exists
         *
         */
        template <typename T>
        std::function<T> getFunction(const std::string& name) const
        {
            return std::function<T>(
                    reinterpret_cast<T*>(getSymbolPointer(name))
            );
        }

        /** \brief Get a function from the library
         *
         * Used only for internal purposes
         *
         * \param name The name of the function
         *
         * \return Return the function or nullptr if the function does not exists
         *
         */
        void* getSymbolPointer(const std::string& name) const;

        /** \brief Free the library
         *
         */
        void free();

        /** \brief Check whether the library is loaded
         *
         * \return Return true if the library is loaded, false otherwise
         *
         */
        operator bool() const;

    private:

        std::unique_ptr<prv::LibraryImpl> m_impl;
    };
}

#endif // BULL_CORE_SYSTEM_LIBRARY_HPP
