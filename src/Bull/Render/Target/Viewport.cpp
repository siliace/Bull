#include <Bull/Render/Target/Viewport.hpp>

namespace Bull
{
    Viewport::Viewport() :
        x(0),
        y(0),
        width(0),
        height(0)
    {
        /// Nothing
    }

    Viewport::Viewport(int x, int y, int width, int height) :
        Viewport(Size(x, y), Size(width, height))
    {
        /// Nothing
    }

    Viewport::Viewport(const Size& position, const Size& size) :
        x(position.width),
        y(position.height),
        width(size.width),
        height(size.height)
    {
        /// Nothing
    }

    bool Viewport::operator==(const Viewport& right) const
    {
        return (x      == right.x) &&
               (y      == right.y) &&
               (width  == right.width) &&
               (height == right.height);
    }

    bool Viewport::operator!=(const Viewport& right) const
    {
        return !((*this) == right);
    }

    void Viewport::move(const Size& offset)
    {
        x += offset.width;
        y += offset.height;
    }

    void Viewport::move(int x, int y)
    {
        move(Size(x, y));
    }
}
