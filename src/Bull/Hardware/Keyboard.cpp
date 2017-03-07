#include <Bull/Hardware/Keyboard.hpp>
#include <Bull/Hardware/KeyboardImpl.hpp>

namespace Bull
{
    bool Keyboard::isKeyPressed(Keyboard::Key key)
    {
        return prv::KeyboardImpl::isKeyPressed(key);
    }
}
