#include <algorithm>

#include <Bull/Core/System/Config.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

#include <Bull/Utility/Log.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Context/Wgl/WglExtensionsLoader.hpp>
    typedef Bull::prv::WglExtensionsLoader ExtensionsLoaderType;
#else
    #include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>
    typedef Bull::prv::GlxExtensionsLoader ExtensionsLoaderType;
#endif

namespace Bull
{
    namespace prv
    {
         /*! \brief Constructor
          *
          * \param handler The handler to use to get supported extensions
          *
          */
         ExtensionsLoader::ExtensionsLoader(SurfaceHandler handler) :
             m_allExtensions(ExtensionsLoaderType::getExtensions(handler))
         {
            /// Nothing
         }

        /*! \brief Add an extension to load
         *
         * \param extension The extension to load
         *
         */
        void ExtensionsLoader::require(const Extension& extension)
        {
            m_extensions.push_back(extension);
        }

        /*! \brief Load required extensions
         *
         */
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
                Log::get()->warning("Extensions has already been loaded");
            }

            m_loaded = true;
        }

        /*! \brief Check whether an OpenGL extension is loaded
         *
         * \param extension The extension
         *
         * \return Return true if loaded, false otherwise
         *
         */
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

        /*! \brief Check whether an OpenGL extension is loaded
         *
         * \param extension The name of the extension
         *
         * \return Return true if loaded, false otherwise
         *
         */
        bool ExtensionsLoader::isLoaded(const String& extension) const
        {
            return isLoaded(Extension(extension, []{return true;}));
        }

        /*! \brief Check whether an OpenGL extension is supported
         *
         * \param extension The extension
         *
         * \return Return true if supported, false otherwise
         *
         */
        bool ExtensionsLoader::isSupported(const Extension& extension) const
        {
            return isSupported(extension.name);
        }

        /*! \brief Check whether an OpenGL extension is supported
         *
         * \param extension The name of the extension
         *
         * \return Return true if supported, false otherwise
         *
         */
        bool ExtensionsLoader::isSupported(const String& extension) const
        {
            return std::find(m_allExtensions.begin(), m_allExtensions.end(), extension) != m_allExtensions.end();
        }
    }
}
