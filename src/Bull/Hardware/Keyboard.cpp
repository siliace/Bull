#include <Bull/Hardware/Keyboard.hpp>
#include <Bull/Hardware/KeyboardImpl.hpp>

namespace Bull
{
    /*! \brief Check if a key is pressed
     *
     * \param key To key to check the state
     *
     * \return Return true if the key is down, false otherwise
     *
     */
    bool Keyboard::isKeyPressed(Keyboard::Key key)
    {
        return prv::KeyboardImpl::isKeyPressed(key);
    }
}
