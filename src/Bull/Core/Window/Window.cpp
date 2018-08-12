
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Core/Window/Window.hpp>
#include <Bull/Core/Window/WindowImpl.hpp>

namespace Bull
{
    Window* Window::s_fullscreen = nullptr;

    const Window* Window::getFullscreen()
    {
        return s_fullscreen;
    }

    Window::Window() :
        m_ignoreNextMouse(false)
    {
        /// Nothing
    }

    Window::Window(const VideoMode& mode, const String& title, Uint32 WindowStyle) :
        Window()
    {
        create(mode, title, WindowStyle);
    }

    void Window::create(const VideoMode& mode, const String& title, Uint32 style)
    {
        if(isOpen())
        {
            close();
        }

        create(prv::WindowImpl::createInstance(mode, title, style), title, style);
    }

    Window::~Window()
    {
        close();
    }

    bool Window::isOpen() const
    {
        return m_impl != nullptr;
    }

    void Window::close()
    {
        enableCaptureCursor(false);

        if(s_fullscreen == this)
        {
            s_fullscreen = nullptr;
        }

        onClose();

        m_impl.reset();
    }

    bool Window::pollEvent(WindowEvent& e)
    {
        if(m_impl && m_impl->popEvent(e, false))
        {
            if(!filterEvent(e))
            {
                e.type = WindowEventType_None;
            }

            return true;
        }

        return false;
    }

    WindowEvent Window::nextEvent()
    {
        WindowEvent e;

        if(m_impl && m_impl->popEvent(e, true))
        {
            filterEvent(e);
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

    void Window::setPosition(const Size& position)
    {
        if(m_impl)
        {
            m_impl->setPosition(position);
        }
    }

    void Window::setPosition(int x, int y)
    {
        return setPosition(Size(x, y));
    }

    Size Window::getPosition() const
    {
        if(m_impl)
        {
            return m_impl->getPosition();
        }

        return Size();
    }

    void Window::setMinSize(const Size& size)
    {
        if(m_impl)
        {
            m_impl->setMinSize(size);
        }
    }

    void Window::setMinSize(int width, int height)
    {
        return setMinSize(Size(width, height));
    }

    Size Window::getMinSize() const
    {
        if(m_impl)
        {
            return m_impl->getMinSize();
        }

        return Size();
    }

    void Window::setMaxSize(const Size& size)
    {
        if(m_impl)
        {
            m_impl->setMaxSize(size);
        }
    }

    void Window::setMaxSize(int width, int height)
    {
        return setMaxSize(Size(width, height));
    }

    Size Window::getMaxSize() const
    {
        if(m_impl)
        {
            return m_impl->getMinSize();
        }

        return Size();
    }

    void Window::setSize(const Size& size)
    {
        if(m_impl)
        {
            m_impl->setSize(size);
        }
    }

    void Window::setSize(unsigned int x, unsigned int y)
    {
        return setSize(Size(x, y));
    }

    Size Window::getSize() const
    {
        if(m_impl)
        {
            return m_impl->getSize();
        }

        return Size();
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

    void Window::setIcon(const Image& icon)
    {
        if(m_impl)
        {
            m_impl->setIcon(icon);
        }
    }

    void Window::setMouseCursor(const Cursor& cursor)
    {
        if(m_impl)
        {
            m_impl->setMouseCursor(cursor.getImpl());
        }
    }

    void Window::setMouseCursorVisible(bool visible)
    {
        if(m_impl)
        {
            m_impl->setMouseCursorVisible(visible);
        }
    }

    bool Window::isMouseCursorVisible() const
    {
        if(m_impl)
        {
            return m_impl->isMouseCursorVisible();
        }

        return false;
    }

    void Window::enableFullscreen(bool fullscreen)
    {
        Expect(m_impl, Throw(LogicError, "Window::enableFullscreen", "The Window is not open"));
        Expect(!s_fullscreen && fullscreen || s_fullscreen == this && !fullscreen, Throw(LogicError, "Window::enableFullscreen", "Another Window is already in fullscreen"));

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
    }
    
    bool Window::isFullscreenEnable() const
    {
        return this == s_fullscreen;
    }

    void Window::create(std::unique_ptr<prv::WindowImpl>&& impl, const String& title, Uint32 style)
    {
        if(style == WindowStyle_Fullscreen && s_fullscreen)
        {
            style = WindowStyle_Default;
        }

        m_impl = std::move(impl);

        if(style == WindowStyle_Fullscreen)
        {
            enableFullscreen(true);
        }

        setTitle(title);
        setVisible(true);
        setMinSize(-1, -1);
        setMaxSize(-1, -1);
        enableKeyRepeat(true);
        setMouseCursorVisible(true);

        onOpen();
    }

    void Window::ignoreNextMouseEvent() const
    {
        m_ignoreNextMouse = true;
    }

    const prv::WindowImpl* Window::getImpl() const
    {
        return m_impl.get();
    }

    bool Window::filterEvent(const WindowEvent& e)
    {
        if(e.type == WindowEventType_Resized)
        {
            onResize();
        }

        if(m_ignoreNextMouse && e.type == WindowEventType_MouseMoved)
        {
            m_ignoreNextMouse = false;

            return false;
        }

        return true;
    }
}
