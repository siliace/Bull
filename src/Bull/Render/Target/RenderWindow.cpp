#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>

namespace Bull
{
    RenderWindow::RenderWindow(const VideoMode& mode, const String& title, Uint32 WindowStyle, const ContextSettings& settings)
    {
        open(mode, title, WindowStyle, settings);
    }

    bool RenderWindow::open(const VideoMode& mode, const String& title, Uint32 WindowStyle, const ContextSettings& settings)
    {
        if(Window::open(mode, title, WindowStyle))
        {
            m_context.reset(prv::GlContext::createInstance(getImpl(), mode.bitsPerPixel, settings));

            return true;
        }

        return false;
    }

    void RenderWindow::display()
    {
        if(m_frameDelay != Time::Zero && m_frameDelay > m_clock.getElapsedTime())
        {
            Thread::sleep(m_frameDelay - m_clock.getElapsedTime());
        }

        if(setActive())
        {
            m_context->display();
        }

        m_clock.restart();
    }

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

    unsigned int RenderWindow::getFramerateLimit() const
    {
        if(m_frameDelay != Time::Zero)
        {
            return static_cast<unsigned int>(1 / m_frameDelay.asSeconds());
        }

        return 0;
    }

    void RenderWindow::enableVsync(bool active)
    {
        if(setActive())
        {
            m_context->enableVsync(active);
        }
    }

    Viewport RenderWindow::getDefaultViewport() const
    {
        Viewport viewport;

        viewport.x      = 0;
        viewport.y      = 0;
        viewport.width  = getSize().x();
        viewport.height = getSize().y();

        return viewport;
    }

    void RenderWindow::onOpen()
    {
        m_clock.start();
    }

    void RenderWindow::onResize()
    {
        resetViewport();
    }

    void RenderWindow::onClose()
    {
        m_context.reset();
    }
}
