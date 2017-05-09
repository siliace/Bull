#ifndef BULL_KEYBOARDIMPL_HPP
#define BULL_KEYBOARDIMPL_HPP

#include <Bull/Hardware/Keyboard.hpp>

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

#endif // BULL_KEYBOARDIMPL_HPP

