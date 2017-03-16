#include <Bull/Window/GlContext.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/RenderTarget.hpp>

namespace Bull
{
    RenderTarget::~RenderTarget()
    {
        /// Nothing
    }

    void RenderTarget::clear(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
    {
        if(setActive())
        {
            gl::clearColor(static_cast<float>(red)   / 255.f,
                           static_cast<float>(green) / 255.f,
                           static_cast<float>(blue)  / 255.f,
                           static_cast<float>(alpha) / 255.f);

            gl::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }

    void RenderTarget::clear(const Color& color)
    {
        clear(color.red, color.green, color.blue, color.alpha);
    }

    bool RenderTarget::setActive(bool active)
    {
        if(m_context)
        {
            return m_context->setActive(active);
        }

        return false;
    }

    void RenderTarget::setViewport(const Viewport& viewport)
    {
        if(setActive())
        {
            m_currentViewport = viewport;

            gl::viewport(m_currentViewport.x, m_currentViewport.y, m_currentViewport.width, m_currentViewport.height);
        }
    }

    const Viewport& RenderTarget::getViewport() const
    {
        return m_currentViewport;
    }

    void RenderTarget::resetViewport()
    {
        setViewport(getDefaultViewport());
    }

    const ContextSettings& RenderTarget::getSettings() const
    {
        if(m_context)
        {
            return m_context->getSettings();
        }

        return ContextSettings::Empty;
    }

    RenderTarget::RenderTarget()
    {
        /// Nothing
    }
}
