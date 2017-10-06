#ifndef BULL_CORE_HARDWARE_XLIB_KEYBOARDIMPL_HPP
#define BULL_CORE_HARDWARE_XLIB_KEYBOARDIMPL_HPP

#include <Bull/Core/Hardware/Keyboard.hpp>

namespace Bull
{
    namespace prv
    {
        struct KeyboardImpl
        {
            /*! \brief Check if a key is pressed
             *
             * \param key To key to check the state
             *
             * \return Return true if the key is down, false otherwise
             *
             */
            static bool isKeyPressed(Keyboard::Key key);
        };
    }
}

#endif // BULL_CORE_HARDWARE_XLIB_KEYBOARDIMPL_HPP

