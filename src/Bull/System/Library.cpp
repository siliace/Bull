#include <Bull/System/Library.hpp>
#include <Bull/System/LibraryImpl.hpp>

namespace Bull
{
    Library::Library(const String& name)
    {
        load(name);
    }

    Library::~Library()
    {
        free();
    }

    bool Library::load(const String& name)
    {
        if(!isLoaded())
        {
            m_impl.reset(prv::LibraryImpl::createInstance(name));

            return isLoaded();
        }

        return false;
    }

    bool Library::isLoaded() const
    {
        return m_impl != nullptr;
    }

    Library::LibFunction Library::getFunction(const String& name)
    {
        if(m_impl)
        {
            m_impl->getFunction(name);
        }

        return nullptr;
    }

    void Library::free()
    {
        m_impl.reset();
    }
}
