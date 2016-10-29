#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Render/Context/GlContext.hpp>

#include <Bull/Window/Window.hpp>
#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    Window* Window::m_fullscreen = nullptr;

    /*! \brief Get the fullscreen window
     *
     * \return Return a pointer to the window in fullscreen
     *
     */
    const Window* Window::getFullscreen()
    {
        return m_fullscreen;
    }

    /*! \brief Constructor
     *
     * \param mode The VideoMode desired
     * \param title The title of the window
     * \param style The window decoration desired
     *
     */
    Window::Window(const VideoMode& mode, const String& title, Uint32 style)
    {
        open(mode, title, style);
    }

    /*! \brief Open the window. If a window was already opened, its closed
     *
     * \param mode  The VideoMode
     * \param title The title of the window
     * \param style The window decorations
     *
     * \return Return true if the window was open successfully
     *
     */
    bool Window::open(const VideoMode& mode, const String& title, Uint32 style)
    {
        return open(mode, title, style, ContextSettings());
    }

    /*! \brief Destructor
     *
     */
    Window::~Window()
    {
        close();
    }

    /*! \brief Check if the window is open
     *
     * \return Return true if the window is open, else return false
     *
     */
    bool Window::isOpen() const
    {
        return m_impl.get();
    }

    /*! \brief Close the window
     *
     */
    void Window::close()
    {
        enableCaptureCursor(false);

        if(m_fullscreen == this)
        {
            m_fullscreen = nullptr;
        }

        m_impl.reset();
        m_context.reset();
    }

    /*! \brief Get the first event on the stack without blocking the current thread
     *
     * \param e An event to fill
     *
     * \return Return true if the event stack was not empty, else return false
     *
     */
    bool Window::pollEvent(Event& e)
    {
        if(m_impl)
        {
            bool success = m_impl->popEvent(e, false);

            return success;
        }

        return false;
    }

    /*! \brief Get the first event on the stack and blocking the current thread
     *
     * \return Return the first event of the stack
     *
     */
    Window::Event Window::nextEvent()
    {
        Window::Event e;

        if(m_impl)
        {
            m_impl->popEvent(e, true);
        }

        return e;
    }

    /*! \brief Enable or disable the capture of the cursor inside the window
     *
     * \param enable The state of the capture
     *
     */
    void Window::enableCaptureCursor(bool enable)
    {
        if(m_impl)
        {
            m_impl->enableCaptureCursor(enable);
        }
    }

    /*! \brief Hide or show the cursor
     *
     * \param enable The state of the cursor
     *
     */
    void Window::showCursor(bool enable)
    {
        if(m_impl)
        {
            m_impl->showCursor(enable);
        }
    }

    /*! \brief Minimize a window
     *
     */
    void Window::minimize()
    {
        if(m_impl)
        {
            m_impl->minimize();
        }
    }

    /*! \brief Check if the window is minimized
     *
     * \return Return true if the window is minimized, false otherwise
     *
     */
    bool Window::isMinimized() const
    {
        if(m_impl)
        {
            return m_impl->isMinimized();
        }

        return false;
    }

    /*! \brief Maximize a window
     *
     */
    void Window::maximize()
    {
        if(m_impl)
        {
            m_impl->maximize();
        }
    }

    /*! \brief Check if the window is maximized
     *
     * \return Return true if the window is maximized, false otherwise
     *
     */
    bool Window::isMaximized() const
    {
        if(m_impl)
        {
            return m_impl->isMaximized();
        }

        return false;
    }

    /*! \brief Set the window position
     *
     * \param position The new position of the window
     *
     */
    void Window::setPosition(const Vector2I& position)
    {
        if(m_impl)
        {
            m_impl->setPosition(position);
        }
    }

    /*! \brief Set the window position
     *
     * \param x The new position of the left side of the window in the screen
     * \param y The new position of the top of the window in the screen
     *
     */
    void Window::setPosition(int x, int y)
    {
        setPosition(Vector2I(x, y));
    }

    /*! \brief Get the position in the screen of the window
     *
     * \return Return the window position
     *
     */
    Vector2I Window::getPosition() const
    {
        if(m_impl)
        {
            return m_impl->getPosition();
        }

        return Vector2I();
    }

    /*! \brief Set the size of the window
     *
     * \param size The new size of the window
     *
     */
    void Window::setSize(const Vector2UI& size)
    {
        if(m_impl)
        {
            m_impl->setSize(size);
        }
    }

    /*! \brief Set the size of the window
     *
     * \param size The new size of the window
     *
     */
    void Window::setSize(unsigned int x, unsigned int y)
    {
        m_impl->setSize(Vector2UI(x, y));
    }

    /*! \brief Set the size of the window
     *
     * \param x The new width of the window
     * \param y The new height of the window
     *
     */
    Vector2UI Window::getSize() const
    {
        if(m_impl)
        {
            return m_impl->getSize();
        }

        return Vector2UI();
    }

    /*! \brief Set the title of the window
     *
     * \param title The new title of the window
     *
     */
    void Window::setTitle(const String& title)
    {
        if(m_impl)
        {
            m_impl->setTitle(title);
        }
    }

    /*! \brief Get the title of the window
     *
     * \return Return the title of the window
     *
     */
    String Window::getTitle() const
    {
        if(m_impl)
        {
            return m_impl->getTitle();
        }

        return String();
    }

    /*! \brief Enable or disable the key repeat
     *
     * \param enable The state of the key repeat
     *
     */
    void Window::enableKeyRepeat(bool enable)
    {
        if(m_impl)
        {
            m_impl->enableKeyRepeat(enable);
        }
    }

    /*! \brief Get the state of the key repeat
     *
     * \param Return true if the key repeat is enable, false otherwise
     *
     */
    bool Window::isKeyRepeatEnable() const
    {
        if(m_impl)
        {
            return m_impl->isKeyRepeatEnable();
        }

        return false;
    }

    /*! \brief Check if the window has the focus
     *
     * \param Return true if the window has the focus, false otherwise
     *
     */
    bool Window::hasFocus() const
    {
        if(m_impl)
        {
            return m_impl->hasFocus();
        }

        return false;
    }

    /*! \brief Show or hide the window
     *
     * \param visible True to show the window, false to hide the window
     *
     */
    void Window::setVisible(bool visible)
    {
        if(m_impl)
        {
            m_impl->setVisible(visible);
        }
    }

    /*! \brief Check if a window is in fullscreen
     *
     * \return Return true if the window is in fullscreen, false otherwise
     *
     */
    bool Window::isFullscreen() const
    {
        return this == m_fullscreen;
    }


    /*! \brief Enter or leave the fullscreen mode
     *
     * \param mode The VideoMode to use
     * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
     *
     * \return Return true if the switch was done successfully, false otherwise
     *
     */
    bool Window::switchFullscreen(const VideoMode& mode, bool fullscreen)
    {
        if(m_impl)
        {
            bool success = m_impl->switchFullscreen(mode, fullscreen);

            if(success && fullscreen)
            {
                m_fullscreen = this;
                enableCaptureCursor();
            }
            else
            {
                enableCaptureCursor(false);
                m_fullscreen = nullptr;
            }

            return success;
        }

        return false;
    }

    /*! \brief Get the window system handler
     *
     * \return Return the native window system handler
     *
     */
    WindowHandler Window::getSystemHandler() const
    {
        if(m_impl)
        {
            return m_impl->getSystemHandler();
        }

        return 0;
    }

    /*! \brief Constructor
     *
     * \param mode     The VideoMode
     * \param title    The title of the window
     * \param style    The window decorations
     * \param settings Settings to use to create the OpenGL context
     *
     */
    Window::Window(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
    {
        open(mode, title, style, settings);
    }

    /*! \brief Open the window. If a window was already opened, its closed
     *
     * \param mode The VideoMode of desired
     * \param title The title of the window
     * \param style The window decoration desired
     * \param settings Parameters to create the OpenGL context
     *
     * \return Return true if the window was open successfully
     *
     */
    bool Window::open(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
    {
        if(isOpen())
        {
            close();
        }

        if(style == Style::Fullscreen && m_fullscreen)
        {
            style = Style::Default;
        }

        m_impl.reset(prv::WindowImpl::createInstance(mode, title, style, settings));
        m_context.reset(prv::GlContext::createInstance(getSystemHandler(), mode.bitsPerPixel, settings));

        if(style == Style::Fullscreen)
        {
            switchFullscreen(mode);
        }

        return true;
    }
}
