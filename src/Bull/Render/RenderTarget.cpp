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

    /*! \brief Activate or deactivate the context
     *
     * \param active True to activate, false to deactivate the context
     *
     * \return Return true if the context's status changed successfully, false otherwise
     *
     */
    bool RenderTarget::setActive(bool active)
    {
        if(m_context)
        {
            return m_context->setActive(active);
        }

        return false;
    }

    /*! \brief Get ContextSettings used to create the context
     *
     * \return Return the ContextSettings
     *
     */
    const ContextSettings& RenderTarget::getSettings() const
    {
        if(m_context)
        {
            return m_context->getSettings();
        }

        return ContextSettings::Empty;
    }

    /*! \brief Default constructor
     *
     */
    RenderTarget::RenderTarget()
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param bitsPerPixel Number of bits per pixel to use
     * \param settings     Settings to use to create the context
     *
     */
    RenderTarget::RenderTarget(const VideoMode& mode, const ContextSettings& settings) :
        m_context(prv::GlContext::createInstance(mode, settings))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param bitsPerPixel Number of bits per pixel to use
     * \param settings     Settings to use to create the context
     *
     */
    RenderTarget::RenderTarget(unsigned int bitsPerPixel, const ContextSettings& settings) :
        m_context(prv::GlContext::createInstance(bitsPerPixel, settings))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param window       The window to bind the created context
     * \param bitsPerPixel The number of bits to use per pixel
     * \param settings     Parameters to create the OpenGL context
     *
     */
    RenderTarget::RenderTarget(WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings) :
        m_context()
    {
        /// Nothing
    }

    /*! \brief Create the internal context
     *
     * \param mode     The VideoMode to use to create the context
     * \param settings Settings to use to create the context
     *
     */
    void RenderTarget::create(const VideoMode& mode, const ContextSettings& settings)
    {
        m_context.reset(prv::GlContext::createInstance(mode, settings));
    }

    /*! \brief Create the internal context
     *
     * \param bitsPerPixel Number of bits per pixel to use
     * \param settings     Settings to use to create the context
     *
     */
    void RenderTarget::create(unsigned int bitsPerPixel, const ContextSettings& settings)
    {
        m_context.reset(prv::GlContext::createInstance(bitsPerPixel, settings));
    }

    /*! \brief Create the internal context
     *
     * \param window       The window to bind the created context
     * \param bitsPerPixel The number of bits to use per pixel
     * \param settings     Parameters to create the OpenGL context
     *
     */
    void RenderTarget::create(WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings)
    {
        m_context.reset(prv::GlContext::createInstance(window, bitsPerPixel, settings));
    }

    /*! \brief Swap buffers of the context
     *
     */
    void RenderTarget::swapBuffers()
    {
        if(m_context && setActive())
        {
            m_context->display();
        }
    }

    /*! \brief Get the internal context
     *
     * \return Return a constant reference to this internal context
     *
     */
    const std::unique_ptr<prv::GlContext>& RenderTarget::getContext() const
    {
        return m_context;
    }
}
