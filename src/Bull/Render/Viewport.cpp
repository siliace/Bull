#include <Bull/Render/Viewport.hpp>

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
        Viewport(Vector2I(x, y), Vector2I(width, height))
    {
        /// Nothing
    }

    Viewport::Viewport(const Vector2I& position, const Vector2I& size) :
        x(position.x),
        y(position.y),
        width(size.x),
        height(size.y)
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

    void Viewport::move(const Vector2I& offset)
    {
        x += offset.x;
        y += offset.y;
    }

    void Viewport::move(int x, int y)
    {
        move(Vector2I(x, y));
    }
}
