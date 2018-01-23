#include <Bull/Core/Utility/Size.hpp>

namespace Bull
{
    Size::Size() :
        width(0),
        height(0)
    {
        /// Nothing
    }

    Size::Size(int width, int height) :
        width(width),
        height(height)
    {
        /// Nothing
    }

    bool Size::operator==(const Size& right) const
    {
        return width  == right.width &&
               height == right.height;
    }

    bool Size::operator!=(const Size& right) const
    {
        return !((*this) == right);
    }

    float Size::getRatio() const
    {
        return width / height;
    }

    Size& Size::operator+=(const Size& right)
    {
        width  += right.width;
        height += right.height;

        return (*this);
    }

    Size& Size::operator-=(const Size& right)
    {
        width  -= right.width;
        height -= right.height;

        return (*this);
    }

    Size& Size::operator*=(int right)
    {
        width  *= right;
        height *= right;

        return (*this);
    }

    Size& Size::operator/=(int right)
    {
        width  /= right;
        height /= right;

        return (*this);
    }

    Size Size::operator+(const Size& right) const
    {
        return Size((*this)) += right;
    }

    Size Size::operator-(const Size& right) const
    {
        return Size((*this)) -= right;
    }

    Size Size::operator*(int right) const
    {
        return Size((*this)) *= right;
    }

    Size Size::operator/(int right) const
    {
        return Size((*this)) /= right;
    }
}