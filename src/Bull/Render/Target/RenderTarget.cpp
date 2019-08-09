#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Target/RenderTarget.hpp>

namespace Bull
{
    RenderTarget::~RenderTarget() = default;

    void RenderTarget::clear(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
    {
        setActive();

        gl::clearColor(static_cast<float>(red)   / 255.f,
                       static_cast<float>(green) / 255.f,
                       static_cast<float>(blue)  / 255.f,
                       static_cast<float>(alpha) / 255.f);

        gl::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(gl::isEnabled(GL_STENCIL_TEST))
        {
            gl::clear(GL_STENCIL_BUFFER_BIT);
        }
    }

    void RenderTarget::clear(const Color& color)
    {
        clear(color.red, color.green, color.blue, color.alpha);
    }

    void RenderTarget::setActive(bool active)
    {
        if(m_context)
        {
            m_context->setActive(active);
        }
    }

    void RenderTarget::setViewport(const Viewport& viewport)
    {
        setActive();

        m_currentViewport = viewport;

        gl::viewport(
                m_currentViewport.position.getWidth(), m_currentViewport.position.getHeight(),
                m_currentViewport.size.getWidth(), m_currentViewport.size.getHeight()
        );
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
}
