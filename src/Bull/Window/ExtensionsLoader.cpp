#include <algorithm>

#include <Bull/Core/Log.hpp>
#include <Bull/Core/System/Config.hpp>

#include <Bull/Window/ExtensionsLoader.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Context/Wgl/WglExtensionsLoader.hpp>
    typedef Bull::prv::WglExtensionsLoader ExtensionsLoaderType;
#else
    #include <Bull/Window/X11/GlxExtensionsLoader.hpp>
    typedef Bull::prv::GlxExtensionsLoader ExtensionsLoaderType;
#endif

namespace Bull
{
    namespace prv
    {
         ExtensionsLoader::ExtensionsLoader(SurfaceHandler handler) :
             m_allExtensions(ExtensionsLoaderType::getExtensions(handler))
         {
            /// Nothing
         }

        void ExtensionsLoader::require(const Extension& extension)
        {
            m_extensions.push_back(extension);
        }

        void ExtensionsLoader::load()
        {
            if(!m_loaded)
            {
                for(Extension& e : m_extensions)
                {
                    if(isSupported(e.name))
                    {
                        e.loaded = e.loader();
                    }
                }
            }
            else
            {
                Log::get()->write("Extensions has already been loaded", Log::Level::Debug);
            }

            m_loaded = true;
        }

        bool ExtensionsLoader::isLoaded(const Extension& extension) const
        {
            for(const Extension& e : m_extensions)
            {
                if(e.name == extension.name)
                {
                    return e.loaded;
                }
            }

            return false;
        }

        bool ExtensionsLoader::isLoaded(const String& extension) const
        {
            return isLoaded(Extension(extension, []{return true;}));
        }

        bool ExtensionsLoader::isSupported(const Extension& extension) const
        {
            return isSupported(extension.name);
        }

        bool ExtensionsLoader::isSupported(const String& extension) const
        {
            return std::find(m_allExtensions.begin(), m_allExtensions.end(), extension) != m_allExtensions.end();
        }
    }
}
