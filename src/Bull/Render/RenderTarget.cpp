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
            glClearColor(static_cast<float>(red / 255.f),
                         static_cast<float>(green / 255.f),
                         static_cast<float>(blue / 255.f),
                         static_cast<float>(alpha / 255.f));

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
}
