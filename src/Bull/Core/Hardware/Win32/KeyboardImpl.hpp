#ifndef BULL_CORE_HARDWARE_WIN32_KEYBOARDIMPL_HPP
#define BULL_CORE_HARDWARE_WIN32_KEYBOARDIMPL_HPP

#include <Bull/Core/Hardware/Keyboard.hpp>

namespace Bull
{
    namespace prv
    {
        class KeyboardImpl
        {
        public:

            /** \brief Check if a key is pressed
             *
             * \param key To key to check the state
             *
             * \return Return true if the key is down, false otherwise
             *
             */
            static bool isKeyPressed(KeyboardKey key);

        private:

            /** \brief Convert a Bull::Keyboard::Key to a windows key value
             *
             * \param vkey To Bull::Keyboard::Key to convert
             *
             * \return Return the VK equivalent
             *
             */
            static int convertBullkeyToVK(KeyboardKey key);
        };
    }
}

#endif // BULL_CORE_HARDWARE_WIN32_KEYBOARDIMPL_HPP

