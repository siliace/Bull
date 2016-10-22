#ifndef Bull_GlxContext_hpp
#define Bull_GlxContext_hpp

#include <GL/glx.h>
#include <X11/Xlib.h>

#include <Bull/Core/Exception.hpp>

#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        class GlxContext : public GlContext
        {
        public:

            /*! \brief Determine the best FrameBuffer configuration
             *
             * \return Return the framebuffer configuration
             *
             */
            static GLXFBConfig getBestConfig();

            /*! \brief Determine the best XVisualInfo
             *
             * \return The XVisualInfo
             *
             */
            static XVisualInfo* getBestVisual();

        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             *
             */
            GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel);

            /*! \brief Destructor
             *
             */
            ~GlxContext();

            /*! \brief Display what has been rendered so far
             *
             */
            void display();

        protected:

            /*! \brief Make the context current
             *
             * \return Return true if the context is now active, false otherwise
             *
             */
            bool makeCurrent();

        private:

            Display::Instance m_display;
            WindowHandler     m_window;
            GLXContext        m_render;
            bool              m_ownWindow;

            DeclarePublicException(InvalidGlxVersion, "Bull require GLX version 1.3 to work",      Log::Critical);
            DeclarePublicException(NoFBConfigFound,   "Failed to retrieve any framebuffer config", Log::Critical);
        };
    }
}

#endif // Bull_GlxContext_hpp
