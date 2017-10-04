#include <Bull/Core/Hardware/Keyboard.hpp>
#include <Bull/Core/Hardware/KeyboardImpl.hpp>

namespace Bull
{
    bool Keyboard::isKeyPressed(Keyboard::Key key)
    {
        return prv::KeyboardImpl::isKeyPressed(key);
    }
}
