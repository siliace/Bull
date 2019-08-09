#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Hardware/MouseImpl.hpp>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    void Mouse::center(const Window& window)
    {
        Size<int> position = window.getPosition();
        Size<unsigned int> size = window.getSize();

        int x = position.getWidth() + size.getWidth();
        int y = position.getHeight() + size.getHeight();

        setPosition(Size<int>{x, y} / 2, window);
    }

    void Mouse::setPosition(const Size<int>& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    void Mouse::setPosition(const Size<int>& position, const Window& relative)
    {
        relative.ignoreNextMouseEvent();
        prv::MouseImpl::setPosition(relative.getPosition() + position);
    }

    Size<int> Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    bool Mouse::isButtonPressed(MouseButton button)
    {
        return prv::MouseImpl::isButtonPressed(button);
    }
}
