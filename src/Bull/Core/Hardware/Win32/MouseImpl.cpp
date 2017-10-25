#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Hardware/Win32/MouseImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void MouseImpl::setPosition(const Vector2I& position)
        {
            SetCursorPos(position.x(), position.y());
        }

        Vector2I MouseImpl::getPosition()
        {
            POINT p;

            GetCursorPos(&p);

            return Vector2I(p.x, p.y);
        }

        bool MouseImpl::isButtonPressed(MouseButton button)
        {
            return (GetAsyncKeyState(convertBullbuttonToVK(button)) & 0x8000) != FALSE;
        }

        int MouseImpl::convertBullbuttonToVK(MouseButton button)
        {
            switch(button)
            {
                case MouseButton_Left:   return VK_LBUTTON;
                case MouseButton_Middle: return VK_MBUTTON;
                case MouseButton_Right:  return VK_RBUTTON;
                case MouseButton_Extra1: return VK_XBUTTON1;
                case MouseButton_Extra2: return VK_XBUTTON2;
            }
        }
    }
}
