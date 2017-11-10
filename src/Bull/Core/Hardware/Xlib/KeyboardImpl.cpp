#include <Bull/Core/Hardware/Xlib/KeyboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        bool KeyboardImpl::isKeyPressed(KeyboardKey key)
        {
            if(key == KeyboardKey_Control)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftControl) || Keyboard::isKeyPressed(KeyboardKey_RightControl);
            }
            else if(key == KeyboardKey_Alt)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftAlt) || Keyboard::isKeyPressed(KeyboardKey_RightAlt);
            }
            else if(key == KeyboardKey_System)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftSystem) || Keyboard::isKeyPressed(KeyboardKey_RightSystem);
            }

            return false;
        }
    }
}
