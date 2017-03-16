#include <Bull/Hardware/Mouse.hpp>
#include <Bull/Hardware/MouseImpl.hpp>

#include <Bull/Window/Window.hpp>

namespace Bull
{
    void Mouse::setPosition(const Vector2I& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(const Vector2I& position, const Window& relativeTo)
    {
        setPosition(relativeTo.getPosition() + position);
    }

    void Mouse::setPosition(int x, int y)
    {
        setPosition(Vector2I(x, y));
    }

    void Mouse::setPosition(int x, int y, const Window& relativeTo)
    {
        setPosition(relativeTo.getPosition() + Vector2I(x, y));
    }

    Vector2I Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    Vector2I Mouse::getPosition(const Window& relativeTo)
    {
        return getPosition() - relativeTo.getPosition();
    }
}
