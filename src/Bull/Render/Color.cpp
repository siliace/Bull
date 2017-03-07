#include <Bull/Render/Color.hpp>

namespace Bull
{
    Color Color::Red         = Color(255, 0,   0);
    Color Color::Green       = Color(0,   255, 0);
    Color Color::Blue        = Color(0,   0,   255);
    Color Color::Yellow      = Color(255, 255, 0);
    Color Color::Magenta     = Color(255, 0,   255);
    Color Color::Cyan        = Color(0,   255, 255);
    Color Color::Black       = Color(0,   0,   0);
    Color Color::White       = Color(255, 255, 255);
    Color Color::Transparent = Color(0,   0,   0,   255);

    /*! \brief Default constructor
     *
     */
    Color::Color() :
        Color(Color::Black)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param red   The red component of the color
     * \param green The green component of the color
     * \param blue  The blue component of the color
     * \param alpha The alpha (opacity) component of the color
     *
     */
    Color::Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) :
        red(red),
        green(green),
        blue(blue),
        alpha(alpha)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param hexa The hexadecimal representation of the color
     *
     */
    Color::Color(Uint32 hexa) :
        red  ((hexa & 0xff000000) >> 24),
        green((hexa & 0x0000ff00) >> 16),
        blue ((hexa & 0x00ff0000) >> 8),
        alpha((hexa & 0x000000ff) >> 0)
    {
        /// Nothing
    }

    /*! \brief Compare two colors
     *
     * \param right The color to compare to this one
     *
     * \return Return true if right and this are the same, false otherwise
     *
     */
    bool Color::operator==(const Color& right)
    {
        return (red == right.red)     &&
               (green == right.green) &&
               (blue == right.blue)   &&
               (alpha == right.alpha);
    }

    /*! \brief Compare two colors
     *
     * \param right The color to compare to this one
     *
     * \return Return true if right and this are not the same, false otherwise
     *
     */
    bool Color::operator!=(const Color& right)
    {
        return !((*this) == right);
    }

    /*! \brief Convert the color to an hexadecimal value
     *
     * \return Return the representation of the color as an hexadecimal value
     *
     */
    Uint32 Color::toHexa() const
    {
        return (red << 24) | (green << 16) | (blue << 8) | (alpha);
    }

    /*! \brief Combine two colors
     *
     * \param right The color to compare to this
     *
     * \return Return the sum of right and this
     *
     */
    Color& Color::operator+=(const Color& right)
    {
        red   += right.red;
        green += right.green;
        blue  += right.blue;
        alpha += right.alpha;

        return (*this);
    }

    /*! \brief Combine two colors
     *
     * \param right The color to compare to this
     *
     * \return Return the sum of right and this
     *
     */
    Color Color::operator+(const Color& right)
    {
        return Color(*this) += right;
    }

    /*! \brief Combine two colors
     *
     * \param right The color to compare to this
     *
     * \return Return the subtract of right and this
     *
     */
    Color& Color::operator-=(const Color& right)
    {
        red   -= right.red;
        green -= right.green;
        blue  -= right.blue;
        alpha -= right.alpha;

        return (*this);
    }

    /*! \brief Combine two colors
     *
     * \param right The color to compare to this
     *
     * \return Return the subtract of right and this
     *
     */
    Color Color::operator-(const Color& right)
    {
        return Color(*this) -= right;
    }
}
