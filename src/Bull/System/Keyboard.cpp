#include <Bull/System/Keyboard.hpp>
#include <Bull/System/KeyboardImpl.hpp>

namespace Bull
{
    bool Keyboard::isKeyPressed(Keyboard::Key key)
    {
        return prv::KeyboardImpl::isKeyPressed(key);
    }
}
