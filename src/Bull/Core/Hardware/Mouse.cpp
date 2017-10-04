#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Hardware/MouseImpl.hpp>

namespace Bull
{
    void Mouse::setPosition(const Vector2I& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(const Vector2I& position, const Window& relative)
    {
        prv::MouseImpl::setPosition(relative.getPosition() + position);
    }

    Vector2I Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    bool Mouse::isButtonPressed(Button button)
    {
        return prv::MouseImpl::isButtonPressed(button);
    }
}
