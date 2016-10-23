#include <Bull/Window/X11/Display.hpp>

#include <Bull/Render/Context/Glx/GlxContext.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         *
         */
        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel) :
            m_window(window),
            m_render(0),
            m_ownWindow(m_window == 0)
        {
            /// Nothing
        }

        /*! \brief Display what has been rendered so far
         *
         */
        void GlxContext::display()
        {
            glXSwapBuffers(Display::get()->getHandler(), m_window);
        }

        /*! \brief Make the context current
         *
         * \return Return true if the context is now active, false otherwise
         *
         */
        bool GlxContext::makeCurrent()
        {
            return glXMakeCurrent(Display::get()->getHandler(), m_window, m_render);
        }
    }
}
