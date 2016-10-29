#ifndef Bull_GlxContext_hpp
#define Bull_GlxContext_hpp

#include <GL/glx.h>
#include <X11/Xlib.h>

#include <Bull/Core/Exception.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/X11/Display.hpp>

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
            static void requireExtensions(const ExtensionsLoader::Instance& loader = ExtensionsLoader::get());

            /*! \brief Determine the best XVisualInfo
             *
             * \param bitsPerPixel Number of bits per pixel
             * \param settings     Settings to use to create the OpenGL context
             *
             * \return The XVisualInfo
             *
             */
            static XVisualInfo getBestVisual(unsigned int bitsPerPixel, const ContextSettings& settings);

        public:

            /*! \brief Default constructor
             *
             */
            GlxContext() = delete;

            /*! \brief Constructor
             *
             * \param shared The shared context
             *
             */
            GlxContext(const std::shared_ptr<GlxContext>& shared);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
             *
             */
            GlxContext(const std::shared_ptr<GlxContext>& shared, unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
             *
             */
            GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            ~GlxContext();

            /*! \brief Display what has been rendered so far
             *
             */
            void display();

            /*! \brief Get the render surface of the context
             *
             * \return Return the render context
             *
             */
            SurfaceHandler getSurfaceHandler() const override;

        protected:

            /*! \brief Make the context current
             *
             * \return Return true if the context is now active, false otherwise
             *
             */
            bool makeCurrent();

        private:

            /*! \brief Create the render surface
             *
             * \param handler The window to bind to this context
             *
             */
            void createSurface(WindowHandler hanlder);

            /*! \brief Create the render surface
             *
             * \param bitsPerPixel The number of bits per pixel to use
             *
             */
            void createSurface(unsigned int bitsPerPixel);

            /*! \brief Create the render context
             *
             * \param shared The shared context
             *
             */
            void createContext(const std::shared_ptr<GlxContext>& shared);

            Display::Instance m_display;
            WindowHandler     m_window;
            GLXContext        m_render;
            bool              m_ownWindow;
        };
    }
}

#endif // Bull_GlxContext_hpp
