#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Hardware/Xlib/MouseImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void MouseImpl::setPosition(const Vector2I& position)
        {
            Display display;

            XWarpPointer(display, None, display.getRootWindow(), 0, 0, 0, 0, position.x, position.y);
            display.flush();
        }

        Vector2I MouseImpl::getPosition()
        {
            int x, y;
            Display display;
            int rootX, rootY;
            ::Window root, child;
            unsigned int buttons;

            if(XQueryPointer(display, display.getRootWindow(), &root, &child, &rootX, &rootY, &x, &y, &buttons))
            {
                return Vector2I(x, y);
            }

            return Vector2I();
        }

        bool MouseImpl::isButtonPressed(Mouse::Button button)
        {
            int x, y;
            Display display;
            int rootX, rootY;
            ::Window root, child;
            unsigned int buttons;

            if(XQueryPointer(display, display.getRootWindow(), &root, &child, &rootX, &rootY, &x, &y, &buttons))
            {
                switch(button)
                {
                    case Mouse::Button::Left:   return buttons & Button1Mask;
                    case Mouse::Button::Middle: return buttons & Button2Mask;
                    case Mouse::Button::Right:  return buttons & Button3Mask;
                    case Mouse::Button::Extra1: return buttons & Button4Mask;
                    case Mouse::Button::Extra2: return buttons & Button5Mask;
                }
            }

            return false;
        }
    }
}
