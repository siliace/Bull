#ifndef BULL_CORE_HARDWARE_KEYBOARD_HPP
#define BULL_CORE_HARDWARE_KEYBOARD_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Hardware/KeyboardKey.hpp>

namespace Bull
{
    class BULL_CORE_API Keyboard
    {
    public:

        /*! \brief Check if a key is pressed
         *
         * \param key To key to check the state
         *
         * \return Return true if the key is down, false otherwise
         *
         */
        static bool isKeyPressed(KeyboardKey key);
    };
}

#endif // BULL_CORE_HARDWARE_KEYBOARD_HPP
