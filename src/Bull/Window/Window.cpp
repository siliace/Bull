#include <Bull/Window/Window.hpp>
#include <Bull/Window/WindowImpl.hpp>
#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    Window* Window::s_fullscreen = nullptr;

    const Window* Window::getFullscreen()
    {
        return s_fullscreen;
    }

    Window::Window()
    {
        /// Nothing
    }

    Window::Window(const VideoMode& mode, const String& title, Uint32 style)
    {
        open(mode, title, style);
    }

    bool Window::open(const VideoMode& mode, const String& title, Uint32 style)
    {
        if(isOpen())
        {
            close();
        }

        if(style == Style::Fullscreen && s_fullscreen)
        {
            style = Style::Default;
        }

        m_impl.reset(prv::WindowImpl::createInstance(mode, title, style));

        if(style == Style::Fullscreen)
        {
            enableFullscreen();
        }

        return true;
    }

    Window::~Window()
    {
        close();
    }

    bool Window::isOpen() const
    {
        return bool(m_impl);
    }

    void Window::close()
    {
        enableCaptureCursor(false);

        if(s_fullscreen == this)
        {
            s_fullscreen = nullptr;
        }

        m_impl.reset();
    }

    bool Window::pollEvent(Event& e)
    {
        if(m_impl)
        {
            bool success = m_impl->popEvent(e, false);

            return success;
        }

        return false;
    }

    Window::Event Window::nextEvent()
    {
        Window::Event e;

        if(m_impl)
        {
            m_impl->popEvent(e, true);
        }

        return e;
    }

    void Window::enableCaptureCursor(bool enable)
    {
        if(m_impl)
        {
            m_impl->enableCaptureCursor(enable);
        }
    }

    void Window::showCursor(bool enable)
    {
        if(m_impl)
        {
            m_impl->showCursor(enable);
        }
    }

    void Window::minimize()
    {
        if(m_impl)
        {
            m_impl->minimize();
        }
    }

    bool Window::isMinimized() const
    {
        if(m_impl)
        {
            return m_impl->isMinimized();
        }

        return false;
    }

    void Window::maximize()
    {
        if(m_impl)
        {
            m_impl->maximize();
        }
    }

    bool Window::isMaximized() const
    {
        if(m_impl)
        {
            return m_impl->isMaximized();
        }

        return false;
    }

    void Window::setPosition(const Vector2I& position)
    {
        if(m_impl)
        {
            m_impl->setPosition(position);
        }
    }

    void Window::setPosition(int x, int y)
    {
        setPosition(Vector2I(x, y));
    }

    Vector2I Window::getPosition() const
    {
        if(m_impl)
        {
            return m_impl->getPosition();
        }

        return Vector2I();
    }

    void Window::setSize(const Vector2UI& size)
    {
        if(m_impl)
        {
            m_impl->setSize(size);
        }
    }

    void Window::setSize(unsigned int x, unsigned int y)
    {
        m_impl->setSize(Vector2UI(x, y));
    }

    Vector2UI Window::getSize() const
    {
        if(m_impl)
        {
            return m_impl->getSize();
        }

        return Vector2UI();
    }

    void Window::setTitle(const String& title)
    {
        if(m_impl)
        {
            m_impl->setTitle(title);
        }
    }

    String Window::getTitle() const
    {
        if(m_impl)
        {
            return m_impl->getTitle();
        }

        return String();
    }

    void Window::enableKeyRepeat(bool enable)
    {
        if(m_impl)
        {
            m_impl->enableKeyRepeat(enable);
        }
    }

    bool Window::isKeyRepeatEnable() const
    {
        if(m_impl)
        {
            return m_impl->isKeyRepeatEnable();
        }

        return false;
    }

    bool Window::hasFocus() const
    {
        if(m_impl)
        {
            return m_impl->hasFocus();
        }

        return false;
    }

    void Window::setVisible(bool visible)
    {
        if(m_impl)
        {
            m_impl->setVisible(visible);
        }
    }

    bool Window::enableFullscreen(bool fullscreen)
    {
        if(m_impl && (!fullscreen || (fullscreen && !s_fullscreen)))
        {
            m_impl->switchFullscreen(fullscreen);

            if(fullscreen)
            {
                s_fullscreen = this;
                enableCaptureCursor();
            }
            else
            {
                enableCaptureCursor(false);
                s_fullscreen = nullptr;
            }

            return true;
        }

        return false;
    }

    bool Window::isFullscreenEnable() const
    {
        return this == s_fullscreen;
    }

    WindowHandler Window::getSystemHandler() const
    {
        if(m_impl)
        {
            return m_impl->getSystemHandler();
        }

        return 0;
    }
}
