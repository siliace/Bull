#include <Bull/Hardware/Xlib/KeyboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        bool KeyboardImpl::isKeyPressed(Keyboard::Key key)
        {
            if(key == Keyboard::Key::Control)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftControl) || Keyboard::isKeyPressed(Keyboard::RightControl);
            }
            else if(key == Keyboard::Key::Alt)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftAlt) || Keyboard::isKeyPressed(Keyboard::RightAlt);
            }
            else if(key == Keyboard::Key::System)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftSystem) || Keyboard::isKeyPressed(Keyboard::RightSystem);
            }

            return false;
        }
    }
}
