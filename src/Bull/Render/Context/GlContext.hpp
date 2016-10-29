#ifndef Bull_GlContext_hpp
#define Bull_GlContext_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Render/Context/ContextSettings.hpp>
#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/SurfaceHandler.hpp>

#include <Bull/Window/WindowHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext : public NonCopyable
        {
        public:

            /*! \brief Perform internal initialization
             *
             */
            static void globalInit();

            /*! \brief Perform internal cleanup
             *
             */
            static void globalCleanup();

            /*! \brief Ensure there is an active OpenGL context in this thread
             *
             */
            static void ensureContext();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \return Return the created context
             *
             */
            static GlContext* createInstance();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param bitsPerPixel Number of bits per pixel to use
             * \param settings     Settings to use to create the context
             *
             * \return Return the created context
             *
             */
            static GlContext* createInstance(unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
             *
             * \return Return the created context
             *
             */
            static GlContext* createInstance(WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Get an OpenGL function
             *
             * \param function The function name
             *
             * \param Return the function, nullptr if the function is not available
             *
             */
            static void* getFunction(const String& function);

            /*! \brief Check whether an extensions is loaded
             *
             * \param  extension The name of the extension
             *
             * \return Return true if the extension is loaded, false otherwise
             *
             */
            static bool isLoaded(const String& extension);

            /*! \brief Check whether an extensions is loaded
             *
             * \param  extension The extension
             *
             * \return Return true if the extension is loaded, false otherwise
             *
             */
            static bool isLoaded(const ExtensionsLoader::Extension& extension);

            /*! \brief Check whether an extensions is loaded
             *
             * \param  extension The name of the extension
             *
             * \return Return true if the extension is supported, false otherwise
             *
             */
            static bool isSupported(const String& extension);

            /*! \brief Check whether an extensions is loaded
             *
             * \param  extension The extension
             *
             * \return Return true if the extension is supported, false otherwise
             *
             */
            static bool isSupported(const ExtensionsLoader::Extension& extension);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~GlContext();

            /*! \brief Activate or deactivate the context
             *
             * \param active True to activate, false to deactivate the context
             *
             * \return Return true if the context's status changed successfully, false otherwise
             *
             */
            bool setActive(bool active);

            /*! \brief Display what has been rendered so far
             *
             */
            virtual void display() = 0;

            /*! \brief Get the render surface of the context
             *
             * \return Return the render context
             *
             */
            virtual SurfaceHandler getSurfaceHandler() const = 0;

            /*! \brief Get the ContextSettings of the context
             *
             * \return Return the ContextSettings
             *
             */
            const ContextSettings& getSettings() const;

        protected:

            /*! \brief Default constructor
             *
             */
            GlContext() = default;

            /*! \brief Constructor
             *
             * \param settings Settings to use to create the context
             *
             */
            GlContext(const ContextSettings& settings);

            /*! \brief Make the context current
             *
             * \return Return true if the context is now active, false otherwise
             *
             */
            virtual bool makeCurrent() = 0;

            ContextSettings m_settings;

        private:

            /*! \brief Enable and perform initializations
             *
             */
            void initialize();
        };
    }
}

#endif // Bull_GlContext_hpp
