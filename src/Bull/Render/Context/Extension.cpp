#include <Bull/Render/Context/Extension.hpp>

namespace Bull
{
    namespace prv
    {
        Extension::Extension(const String& name, const std::function<bool()>& loader) :
            m_name(name),
            m_loaded(false),
            m_loader(loader)
        {
            /// Nothing
        }

        void Extension::load()
        {
            m_loaded = m_loader();
        }

        bool Extension::isLoaded() const
        {
            return m_loaded;
        }

        const String& Extension::getName() const
        {
            return m_name;
        }
    }
}