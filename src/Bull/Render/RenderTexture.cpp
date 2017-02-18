#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/RenderTexture.hpp>
#include <Bull/Render/RenderTextureImplDefault.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    RenderTexture::RenderTexture()
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    RenderTexture::~RenderTexture()
    {
        /// Nothing
    }

    /*! \brief Create the RenderTexture
     *
     * \param size  The size of the RenderTexture
     * \param color The color to fill the RenderTexture
     * \param settings Settings to use to create the RenderTexture
     *
     * \return Return true if the RenderTexture was created successfully, false otherwise
     *
     */
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

    /*! \brief Get the default viewport of the RenderTarget
     *
     * \return Return the viewport
     *
     */
    Viewport RenderTexture::getDefaultViewport() const
    {
        Viewport viewport;

        viewport.x      = 0;
        viewport.y      = 0;
        viewport.width  = m_target.getSize().x;
        viewport.height = m_target.getSize().y;

        return viewport;
    }

    /*! \brief Display what has been rendered so far into the target texture
     *
     */
    void RenderTexture::display()
    {
        if(m_impl && m_context->setActive(true))
        {
            m_impl->updateTarget();
        }
    }

    /*! \brief Get the size of the RenderTexture
     *
     * \return Return the size
     *
     */
    const Vector2UI& RenderTexture::getSize() const
    {
        return m_target.getSize();
    }

    /*! \brief Get the target texture
     *
     * \return Return the texture
     *
     */
    const Texture& RenderTexture::getTexture() const
    {
        return m_target;
    }

    /*! \brief Convert the RenderTexture to a texture
     *
     * \return Return the texture
     *
     */
    RenderTexture::operator const Texture&() const
    {
        return m_target;
    }
}
