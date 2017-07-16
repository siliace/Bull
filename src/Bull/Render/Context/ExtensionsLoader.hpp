#ifndef Bull_ExtensionsLoader_hpp
#define Bull_ExtensionsLoader_hpp

#include <vector>

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Context/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class ExtensionsLoader : public Singleton<ExtensionsLoader>
        {
        public:

            struct Extension
            {
                /*! \brief Constructor
                 *
                 * \param name The name of the extension
                 * \param loader The function to call to load the extension
                 *
                 */
                Extension(const String& name, Functor<bool> loader) :
                    name(name),
                    loader(loader),
                    loaded(false)
                {
                    /// Nothing
                }

                String        name;
                Functor<bool> loader;
                bool          loaded;
            };

        public:

            /*! \brief Default constructor
             *
             */
            ExtensionsLoader() = default;

            /*! \brief Constructor
             *
             * \param handler The handler to use to get supported extensions
             *
             */
            ExtensionsLoader(SurfaceHandler handler);

            /*! \brief Add an extension to load
             *
             * \param extension The extension to load
             *
             */
            void require(const Extension& extension);

            /*! \brief Load required extensions
             *
             */
            void load();

            /*! \brief Check whether an OpenGL extension is loaded
             *
             * \param extension The extension
             *
             * \return Return true if loaded, false otherwise
             *
             */
            bool isLoaded(const Extension& extension) const;

            /*! \brief Check whether an OpenGL extension is loaded
             *
             * \param extension The name of the extension
             *
             * \return Return true if loaded, false otherwise
             *
             */
            bool isLoaded(const String& extension) const;

            /*! \brief Check whether an OpenGL extension is supported
             *
             * \param extension The extension
             *
             * \return Return true if supported, false otherwise
             *
             */
            bool isSupported(const Extension& extension) const;

            /*! \brief Check whether an OpenGL extension is supported
             *
             * \param extension The name of the extension
             *
             * \return Return true if supported, false otherwise
             *
             */
            bool isSupported(const String& extension) const;

        private:

            std::vector<Extension> m_extensions;
            std::vector<String>    m_allExtensions;
            bool                   m_loaded = false;
        };
    }
}

#endif // Bull_ExtensionsLoader_hpp
