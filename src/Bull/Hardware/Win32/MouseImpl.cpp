#include <windows.h>

#include <Bull/Hardware/Win32/MouseImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void MouseImpl::setPosition(const Vector2I& position)
        {
            SetCursorPos(position.x, position.y);
        }

        Vector2I MouseImpl::getPosition()
        {
            POINT p;

            GetCursorPos(&p);

            return Vector2I(p.x, p.y);
        }

        bool MouseImpl::isButtonPressed(Mouse::Button button)
        {
            /// Todo : implementation

            return false;
        }
    }
}
