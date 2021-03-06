#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/System/Library.hpp>
#include <Bull/Core/System/LibraryImpl.hpp>

namespace Bull
{
    Library::Library(const std::string& name)
    {
        load(name);
    }

    Library::~Library()
    {
        free();
    }

    void Library::load(const std::string& name)
    {
        if(isLoaded())
        {
            free();
        }

        m_impl = prv::LibraryImpl::createInstance(name);
    }

    bool Library::isLoaded() const
    {
        return m_impl != nullptr;
    }

    void* Library::getSymbolPointer(const std::string& name) const
    {
        if(isLoaded())
        {
            return m_impl->getSymbolPointer(name);
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
