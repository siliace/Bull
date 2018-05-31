#ifndef BULL_RENDER_CONTEXT_GLX_GLXCONTEXT_HPP
#define BULL_RENDER_CONTEXT_GLX_GLXCONTEXT_HPP

#include <GL/glx.h>

#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    namespace prv
    {
        class GlxContext : public GlContext
        {
        public:

            /*! \brief Get an OpenGL function
             *
             * \param function The function name
             *
             * \param Return the function, nullptr if the function is not available
             *
             */
            static void* getFunction(const String& function);

            /*! \brief Set the list of extensions to load
             *
             * \param loader The instance of the extension loader to use
             *
             */
            static void requireExtensions(ExtensionsLoader::Instance& loader);

            /*! \brief Get the best config according to context settings
             *
             * \param settings     Context settings
             * \param bitsPerPixel The number of bits per pixel to use
             *
             * \return The best config
             *
             */
            static GLXFBConfig chooseBestConfig(Display::Instance display, const ContextSettings& settings, Uint8 bitsPerPixel);

        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             *
             */
            explicit GlxContext(const GlxContext* shared);

            /*! \brief Constructor
             *
             * \param shared   The shared context
             * \param mode     The VideoMode to use to create the context
             * \param settings Settings to use to create the context
             *
             */
            GlxContext(const GlxContext* shared, const VideoMode& mode, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
             *
             */
            GlxContext(const GlxContext* shared, Uint8 bitsPerPixel, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
             *
             */
            GlxContext(const GlxContext* shared, const WindowImpl& window, Uint8 bitsPerPixel, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            ~GlxContext();

            /*! \brief Display what has been rendered so far
             *
             */
            void display() override;

            /*! \brief Activate or deactivate the vertical synchronization
             *
             * \param active True to activate, false to deactivate
             *
             * \return Return true if success, false otherwise
             *
             */
            void enableVsync(bool active) override;

            /*! \brief Get the render surface of the context
             *
             * \return Return the render context
             *
             */
            SurfaceHandler getSurfaceHandler() const override;

        protected:

            /*! \brief Make the context current
             *
             */
            void makeCurrent() override;

        private:

            /*! \brief Create the render surface
             *
             * \param window The window to bind to this context
             *
             */
            void createSurface(const WindowImpl& window);

            /*! \brief Create the render surface
             *
             * \param shared The shared context
             * \param width  The width of the surface
             * \param height The height of the surface
             *
             */
            void createSurface(const GlxContext* shared, unsigned int width, unsigned int height);

            /*! \brief Create the render context
             *
             * \param shared The shared context
             *
             */
            void createContext(const GlxContext* shared);

            /*! \brief Update the ContextSettings according to the created context
             *
             */
            void updateSettings();

            Log::Instance             m_log;
            XWindow                   m_window;
            GLXContext                m_render;
            GLXFBConfig               m_config;
            GLXPbuffer                m_pbuffer;
            mutable Display::Instance m_display;
            XColormap                 m_colormap;
            bool                      m_ownWindow;
        };
    }
}

#endif // BULL_RENDER_CONTEXT_GLX_GLXCONTEXT_HPP
