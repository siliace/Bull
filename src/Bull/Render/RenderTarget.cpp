#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/RenderTarget.hpp>

namespace Bull
{
    /*! \brief Destructor
     *
     */
    RenderTarget::~RenderTarget()
    {
        /// Nothing
    }

    /*! \brief Clear the RenderTarget with the specified color
     *
     * \param red   The red component of the color
     * \param green The green component of the color
     * \param blue  The blue component of the color
     * \param alpha The alpha component of the color
     *
     */
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

    /*! \brief Clear the RenderTarget with the specified color
     *
     * \param color The color to use
     *
     */
    void RenderTarget::clear(const Color& color)
    {
        clear(color.red, color.green, color.blue, color.alpha);
    }

    /*! \brief Change the viewport of the RenderTarget
     *
     * \param viewport The viewport
     *
     */
    void RenderTarget::setViewport(const Viewport& viewport)
    {
        m_currentViewport = viewport;

        gl::viewport(m_currentViewport.x, m_currentViewport.y, m_currentViewport.width, m_currentViewport.height);
    }

    /*! \brief Get the current viewport of the RenderTarget
     *
     * \return Return the viewport
     *
     */
    const Viewport& RenderTarget::getViewport() const
    {
        return m_currentViewport;
    }

    /*! \brief Reset the viewport by the default one
     *
     */
    void RenderTarget::resetViewport()
    {
        setViewport(getDefaultViewport());
    }

    /*! \brief Default constructor
     *
     */
    RenderTarget::RenderTarget()
    {
        /// Nothing
    }
}
