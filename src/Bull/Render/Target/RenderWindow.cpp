#include <Bull/Core/Concurrency/Thread.hpp>

#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Target/RenderWindowImpl.hpp>

namespace Bull
{
    RenderWindow::RenderWindow(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
    {
        create(mode, title, style, settings);
    }

    void RenderWindow::create(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
    {
        Window::create(prv::RenderWindowImpl::createInstance(mode, title, style, settings), title, style);

        m_context = prv::GlContext::createInstance(*m_impl, mode.bitsPerPixel, settings);
    }

    void RenderWindow::display()
    {
        if(m_frameDelay != Duration::Zero && m_frameDelay > m_clock.getElapsedTime())
        {
            Thread::sleep(m_frameDelay - m_clock.getElapsedTime());
        }

        setActive();
        m_context->display();

        m_clock.restart();
    }

    void RenderWindow::setFramerateLimit(unsigned int limit)
    {
        if(limit)
        {
            m_frameDelay = Duration::seconds(1 / static_cast<float>(limit));
        }
        else
        {
            m_frameDelay = Duration::Zero;
        }
    }

    unsigned int RenderWindow::getFramerateLimit() const
    {
        if(m_frameDelay != Duration::Zero)
        {
            return static_cast<unsigned int>(1 / m_frameDelay.asSeconds());
        }

        return 0;
    }

    void RenderWindow::enableVsync(bool active)
    {
        setActive();
        m_context->enableVsync(active);
    }

    Viewport RenderWindow::getDefaultViewport() const
    {
        Viewport viewport;

        viewport.x      = 0;
        viewport.y      = 0;
        viewport.width  = getSize().width;
        viewport.height = getSize().height;

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
