#include <Bull/Core/System/Library.hpp>
#include <Bull/Core/System/LibraryImpl.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    Library::Library()
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param name The name or the path to the library to load
     *
     */
    Library::Library(const String& name)
    {
        load(name);
    }

    /*! \brief Destructor
     *
     */
    Library::~Library()
    {
        free();
    }

    /*! \brief Load a library
     *
     * \param name The name or the path to the library to load
     *
     * \return Return true if the library is loaded, false otherwise
     *
     */
    bool Library::load(const String& name)
    {
        if(!isLoaded())
        {
            m_impl.reset(prv::LibraryImpl::createInstance(name));

            return isLoaded();
        }

        return false;
    }

    /*! \brief Check whether the library is loaded
     *
     * \return Return true if the library is loaded, false otherwise
     *
     */
    bool Library::isLoaded() const
    {
        return m_impl.get() != nullptr;
    }

    /*! \brief Get a function from the library
     *
     * \param name The name of the function
     *
     * \return Return the function or nullptr if the function does not exists
     *
     */
    Library::LibFunction Library::getFunction(const String& name)
    {
        if(m_impl)
        {
            m_impl->getFunction(name);
        }

        return nullptr;
    }

    /*! \brief Free the library
     *
     */
    void Library::free()
    {
        m_impl.reset(nullptr);
    }
}
