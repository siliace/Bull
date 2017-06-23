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
            return (GetAsyncKeyState(convertBullbuttonToVK(button)) & 0x8000) != FALSE;
        }

        int MouseImpl::convertBullbuttonToVK(Mouse::Button button)
        {
            switch(button)
            {
                case Mouse::Button::Left:   return VK_LBUTTON;
                case Mouse::Button::Middle: return VK_MBUTTON;
                case Mouse::Button::Right:  return VK_RBUTTON;
                case Mouse::Button::Extra1: return VK_XBUTTON1;
                case Mouse::Button::Extra2: return VK_XBUTTON2;
            }
        }
    }
}
