#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/System/Library.hpp>
#include <Bull/Core/System/LibraryImpl.hpp>

namespace Bull
{
    Library::Library(const String& name)
    {
        if(!load(name))
        {
            Throw(InternalError, "Library::Library", "Failed to load library " + name);
        }
    }

    Library::~Library()
    {
        free();
    }

    bool Library::load(const String& name)
    {
        if(!isLoaded())
        {
            m_impl = prv::LibraryImpl::createInstance(name);

            return isLoaded();
        }

        return false;
    }

    bool Library::isLoaded() const
    {
        if(m_impl)
        {
            return m_impl->isLoaded();
        }

        return false;
    }

    Library::LibFunction Library::getFunction(const String& name)
    {
        if(isLoaded())
        {
            return m_impl->getFunction(name);
        }

        return nullptr;
    }

    void Library::free()
    {
        m_impl.reset();
    }

    Library::operator bool() const
    {
        return isLoaded();
    }
}
