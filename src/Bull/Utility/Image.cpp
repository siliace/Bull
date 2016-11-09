#include <Bull/Utility/Image.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param width  The width of the image to create
     * \param height The height of the image to create
     * \param color  The color to fill the image
     *
     */
    Image::Image(unsigned int width, unsigned int height, const Color& color) :
        m_pixels(width * height * 4),
        m_size(width, height)
    {
        for(unsigned int i = 0; i < m_pixels.size(); i += 4)
        {
            m_pixels[i]     = color.red;
            m_pixels[i + 1] = color.green;
            m_pixels[i + 2] = color.blue;
            m_pixels[i + 3] = color.alpha;
        }
    }

    /*! \brief Set the color of a pixel
     *
     * \param x
     * \param y
     * \param color
     *
     */
    void Image::set(unsigned int x, unsigned int y, const Color& color)
    {
        unsigned int position = x * y * 4;

        if(position > m_size.x * m_size.y * 4)
        {
            ThrowException(OutOfRange);
        }

        m_pixels[position]     = color.red;
        m_pixels[position + 1] = color.green;
        m_pixels[position + 2] = color.blue;
        m_pixels[position + 3] = color.alpha;
    }

    /*! \brief Get the color of a pixel
     *
     * \param x
     * \param y
     *
     * \return Return the color
     *
     */
    Color Image::get(unsigned int x, unsigned int y) const
    {
        unsigned int position = x * y * 4;

        if(position > m_size.x * m_size.y * 4)
        {
            ThrowException(OutOfRange);
        }

        Uint8 red   = m_pixels[position];
        Uint8 green = m_pixels[position + 1];
        Uint8 blue  = m_pixels[position + 2];
        Uint8 alpha = m_pixels[position + 3];

        return Color(red, green, blue, alpha);
    }

    /*! \brief Get the size of the image
     *
     * \return Return the size
     *
     */
    const Vector2UI& Image::getSize() const
    {
        return m_size;
    }

    /*! \brief Get pixels of the image
     *
     * \return Return pixels
     *
     */
    const std::vector<Uint8>& Image::getPixels() const
    {
        return m_pixels;
    }
}
