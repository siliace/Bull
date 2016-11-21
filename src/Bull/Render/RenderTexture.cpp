#include <Bull/Render/RenderTexture.hpp>
#include <Bull/Render/RenderTextureImplDefault.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    RenderTexture::RenderTexture() :
        m_impl(nullptr)
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
     * \param size  The size of RenderTexture
     * \param color The color to fill the RenderTexture
     *
     * \return Return true if the RenderTexture was created successfully, false otherwise
     *
     */
    bool RenderTexture::create(const Vector2UI size, Color color)
    {
        if(m_target.create(size))
        {
            m_impl.reset(new prv::RenderTextureImplDefault());

            if(m_impl)
            {
                if(m_impl->create(size, m_target.getSystemHandler(), true))
                {
                    clear(color);

                    return true;
                }
            }
        }

        return false;
    }

    /*! \brief Create the RenderTexture
     *
     * \param width  The width of the RenderTexture
     * \param height The height of the RenderTexture
     * \param color  The color to fill the RenderTexture
     *
     * \return Return true if the RenderTexture was created successfully, false otherwise
     *
     */
    bool RenderTexture::create(unsigned int width, unsigned int height, Color color)
    {
        return create(Vector2UI(width, height), color);
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

    /*! \brief Activate or deactivate the context
     *
     * \param active True to activate, false to deactivate the context
     *
     * \return Return true if the context's status changed successfully, false otherwise
     *
     */
    bool RenderTexture::setActive(bool active)
    {
        if(m_impl)
        {
            return m_impl->setActive(active);
        }

        return false;
    }

    /*! \brief Display what has been rendered so far into the target texture
     *
     */
    void RenderTexture::display()
    {
        if(m_impl)
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
