#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Hardware/MouseImpl.hpp>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    void Mouse::center(const Window& window)
    {
        setPosition(window.getSize() / 2, window);
    }

    void Mouse::setPosition(const Size& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(const Size& position, const Window& relative)
    {
        relative.ignoreNextMouseEvent();
        prv::MouseImpl::setPosition(relative.getPosition() + position);
    }

    Size Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    bool Mouse::isButtonPressed(MouseButton button)
    {
        return prv::MouseImpl::isButtonPressed(button);
    }
}
