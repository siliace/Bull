#ifndef BULL_RENDER_CONTEXT_EXTENSIONSLOADER_HPP
#define BULL_RENDER_CONTEXT_EXTENSIONSLOADER_HPP

#include <set>

#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Render/Context/Extension.hpp>
#include <Bull/Render/Context/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class ExtensionsLoader : public Singleton<ExtensionsLoader>
        {
        private:

            /*! \brief Get all extensions available on the system
             *
             * \param surface The surface to get extensions from
             *
             * \return The list of extensions
             *
             */
            static std::set<String> getAllExtensions(SurfaceHandler surface);

        public:

            /*! \brief Default constructor
             *
             */
            ExtensionsLoader();

            /*! \brief Add an extension to load
             *
             * \param extension The extension to load
             *
             */
            void require(Extension& extension);

            /*! \brief Load required extensions
             *
             * \param surface The surface to get extensions from
             *
             */
            void loadExtensions(SurfaceHandler surface);

            /*! \brief Load OpenGL functions
             *
             */
            void loadFunctions();

            /*! \brief Check whether an OpenGL extension is supported
             *
             * \param extension The name of the extension
             *
             * \return Return true if supported, false otherwise
             *
             */
            bool isSupported(const String& extension) const;

        private:

            std::vector<std::reference_wrapper<Extension>> m_extensions;
            std::set<String>                               m_allExtensions;
            bool                                           m_loadedFunctions;
            bool                                           m_loadedExtensions;
        };
    }
}

#endif // BULL_RENDER_CONTEXT_EXTENSIONSLOADER_HPP
