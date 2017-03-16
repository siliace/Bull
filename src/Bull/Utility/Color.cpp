#include <Bull/Utility/Color.hpp>

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

    Color::Color() :
        Color(Color::Black)
    {
        /// Nothing
    }

    Color::Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) :
        red(red),
        green(green),
        blue(blue),
        alpha(alpha)
    {
        /// Nothing
    }

    Color::Color(Uint32 hexa) :
        red  ((hexa & 0xff000000) >> 24),
        green((hexa & 0x0000ff00) >> 16),
        blue ((hexa & 0x00ff0000) >> 8),
        alpha((hexa & 0x000000ff) >> 0)
    {
        /// Nothing
    }

    bool Color::operator==(const Color& right)
    {
        return (red == right.red)     &&
               (green == right.green) &&
               (blue == right.blue)   &&
               (alpha == right.alpha);
    }

    bool Color::operator!=(const Color& right)
    {
        return !((*this) == right);
    }

    Uint32 Color::toHexa() const
    {
        return (red << 24) | (green << 16) | (blue << 8) | (alpha);
    }

    Color& Color::operator+=(const Color& right)
    {
        red   += right.red;
        green += right.green;
        blue  += right.blue;
        alpha += right.alpha;

        return (*this);
    }

    Color Color::operator+(const Color& right)
    {
        return Color(*this) += right;
    }

    Color& Color::operator-=(const Color& right)
    {
        red   -= right.red;
        green -= right.green;
        blue  -= right.blue;
        alpha -= right.alpha;

        return (*this);
    }

    Color Color::operator-(const Color& right)
    {
        return Color(*this) -= right;
    }
}
