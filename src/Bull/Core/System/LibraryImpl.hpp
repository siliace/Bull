#ifndef Bull_LibraryImpl_hpp
#define Bull_LibraryImpl_hpp

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
             * \return Return the created instance
             *
             */
            static LibraryImpl* createInstance(const String& name);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~LibraryImpl();

            /*! \brief Load a library
             *
             * \param name The name or the path to the library to load
             *
             * \return Return true if the library is loaded, false otherwise
             *
             */
            virtual bool load(const String& name) = 0;

            /*! \brief Get a function from the library
             *
             * \param name The name of the function
             *
             * \return Return the function or nullptr if the function does not exists
             *
             */
            virtual Library::LibFunction getFunction(const String& name) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            LibraryImpl() = default;
        };
    }
}

#endif // Bull_LibraryImpl_hpp
