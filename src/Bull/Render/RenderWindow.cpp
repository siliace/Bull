#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Render/RenderWindow.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    RenderWindow::RenderWindow()
    {
        m_clock.start();
    }

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
        m_clock.start();
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

        if(m_frameDelay != Time::Zero && m_frameDelay > m_clock.getElapsedTime())
        {
            Thread::sleep(m_frameDelay - m_clock.getElapsedTime());
        }

        m_clock.restart();
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

    /*! \brief Set the maximum framerate of the RenderWindow
     *
     * \param limit The maximum
     *
     */
    void RenderWindow::setFramerateLimit(unsigned int limit)
    {
        if(limit)
        {
            m_frameDelay = Time::seconds(1 / static_cast<float>(limit));
        }
        else
        {
            m_frameDelay = Time::Zero;
        }
    }

    /*! \brief Get the maximum framerate of the RenderWindow
     *
     * \param limit The maximum
     *
     */
    unsigned int RenderWindow::getFramerateLimit() const
    {
        if(m_frameDelay != Time::Zero)
        {
            return static_cast<unsigned int>(1 / m_frameDelay.asSeconds());
        }

        return 0;
    }

    /*! \brief Activate or deactivate the vertical synchronization
     *
     * \param active True to activate, false to deactivate
     *
     * \return Return true if success, false otherwise
     *
     */
    void RenderWindow::enableVsync(bool active)
    {
        if(m_context)
        {
            m_context->enableVsync(active);
        }
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
