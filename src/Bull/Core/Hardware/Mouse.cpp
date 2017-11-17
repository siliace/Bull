#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Hardware/MouseImpl.hpp>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    void Mouse::center(const Window& window)
    {
        setPosition(window.getSize() / static_cast<unsigned int>(2), window);
    }

    void Mouse::setPosition(const Vector2I& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(const Vector2I& position, const Window& relative)
    {
        relative.ignoreNextMouseEvent();
        prv::MouseImpl::setPosition(relative.getPosition() + position);
    }

    Vector2I Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    bool Mouse::isButtonPressed(MouseButton button)
    {
        return prv::MouseImpl::isButtonPressed(button);
    }
}
