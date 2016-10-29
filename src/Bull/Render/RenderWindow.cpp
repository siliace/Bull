#include <Bull/Render/RenderWindow.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param mode     The VideoMode
     * \param title    The title of the window
     * \param style    The window decorations
     * \param settings Settings to use to create the OpenGL context
     *
     */
    RenderWindow::RenderWindow(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings) :
        Window(mode, title, style, settings)
    {
        /// Nothing
    }

    /*! \brief Open the window. If a window was already opened, its closed
     *
     * \param mode     The VideoMode
     * \param title    The title of the window
     * \param style    The window decorations
     * \param settings Settings to use to create the OpenGL context
     *
     * \return Return true if the window was open successfully
     *
     */
    bool RenderWindow::open(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
    {
        return Window::open(mode, title, style, settings);
    }

    /*! \brief Display what has been rendered so far
     *
     */
    void RenderWindow::display()
    {
        if(setActive())
        {
            m_context->display();
        }
    }

    /*! \brief Activate or deactivate the context
     *
     * \param active True to activate, false to deactivate the context
     *
     * \return Return true if the context's status changed successfully, false otherwise
     *
     */
    bool RenderWindow::setActive(bool active)
    {
        if(m_context)
        {
            return m_context->setActive(active);
        }

        return false;
    }

    /*! \brief Get ContextSettings used to create the context
     *
     * \return Return the ContextSettings
     *
     */
    const ContextSettings& RenderWindow::getSettings() const
    {
        if(m_context)
        {
            return m_context->getSettings();
        }

        return ContextSettings();
    }
}
