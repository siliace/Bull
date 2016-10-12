#ifndef Bull_Library_hpp
#define Bull_Library_hpp

#include <functional>
#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/String.hpp>

namespace Bull
{
    namespace prv
    {
        class LibraryImpl;
    }

    class Library : public NonCopyable
    {
    public:

        using LibFunction = int(*)();

    public:

        /*! \brief Default constructor
         *
         */
        Library();

        /*! \brief Constructor
         *
         * \param name The name or the path to the library to load
         *
         */
        Library(const String& name);

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

#endif // Bull_Library_hpp
