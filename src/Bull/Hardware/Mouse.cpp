#include <Bull/Hardware/Mouse.hpp>
#include <Bull/Hardware/MouseImpl.hpp>

#include <Bull/Window/Window.hpp>

namespace Bull
{
    void Mouse::setPosition(const Vector2I& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(int x, int y)
    {
        setPosition(Vector2I(x, y));
    }

    Vector2I Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }
}
