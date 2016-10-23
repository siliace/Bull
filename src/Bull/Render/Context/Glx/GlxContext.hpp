#ifndef Bull_GlxContext_hpp
#define Bull_GlxContext_hpp

#include <GL/glx.h>

#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    namespace prv
    {
        class GlxContext : public GlContext
        {
        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             *
             */
            GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel);

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

            WindowHandler m_window;
            GLXContext    m_render;
            bool          m_ownWindow;
        };
    }
}

#endif // Bull_GlxContext_hpp
