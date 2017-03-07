#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/RenderTexture.hpp>
#include <Bull/Render/RenderTextureImplDefault.hpp>

namespace Bull
{
    RenderTexture::RenderTexture()
    {
        /// Nothing
    }

    RenderTexture::~RenderTexture()
    {
        /// Nothing
    }

    bool RenderTexture::create(const Vector2UI& size, Color color, const ContextSettings& settings)
    {
        m_context.reset(prv::GlContext::createInstance(VideoMode(size.x, size.y), settings));

        if(m_context->setActive(true) && m_target.create(m_size))
        {
            m_impl.reset(new prv::RenderTextureImplDefault());

            if(m_impl)
            {
                return m_impl->create(m_target.getSize(), m_target.getSystemHandler());
            }
        }

        return false;
    }

    Viewport RenderTexture::getDefaultViewport() const
    {
        Viewport viewport;

        viewport.x      = 0;
        viewport.y      = 0;
        viewport.width  = m_target.getSize().x;
        viewport.height = m_target.getSize().y;

        return viewport;
    }

    void RenderTexture::display()
    {
        if(m_impl && m_context->setActive(true))
        {
            m_impl->updateTarget();
        }
    }

    const Vector2UI& RenderTexture::getSize() const
    {
        return m_target.getSize();
    }

    const Texture& RenderTexture::getTexture() const
    {
        return m_target;
    }

    RenderTexture::operator const Texture&() const
    {
        return m_target;
    }
}
