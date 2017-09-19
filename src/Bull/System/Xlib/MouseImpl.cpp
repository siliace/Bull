#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/System/Xlib/MouseImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void MouseImpl::setPosition(const Vector2I& position)
        {
            Display::Instance display = Display::get();

            XWarpPointer(display->getHandler(), XNone, display->getRootWindow(), 0, 0, 0, 0, position.x, position.y);
            display->flush();
        }

        Vector2I MouseImpl::getPosition()
        {
            int x, y;
            int rootX, rootY;
            XWindow root, child;
            unsigned int buttons;
            Display::Instance display = Display::get();

            if(XQueryPointer(display->getHandler(), display->getRootWindow(), &root, &child, &rootX, &rootY, &x, &y, &buttons))
            {
                return Vector2I(x, y);
            }

            return Vector2I();
        }

        bool MouseImpl::isButtonPressed(Mouse::Button button)
        {
            int x, y;
            int rootX, rootY;
            XWindow root, child;
            unsigned int buttons;
            Display::Instance display = Display::get();

            if(XQueryPointer(display->getHandler(), display->getRootWindow(), &root, &child, &rootX, &rootY, &x, &y, &buttons))
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
