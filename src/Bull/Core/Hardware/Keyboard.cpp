#include <Bull/Core/Hardware/Keyboard.hpp>
#include <Bull/Core/Hardware/KeyboardImpl.hpp>

namespace Bull
{
    bool Keyboard::isKeyPressed(KeyboardKey key)
    {
        return prv::KeyboardImpl::isKeyPressed(key);
    }
}
