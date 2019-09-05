#ifndef BULL_CORE_HARDWARE_WIN32_MOUSEIMPL_HPP
#define BULL_CORE_HARDWARE_WIN32_MOUSEIMPL_HPP

#include <Bull/Core/Hardware/MouseButton.hpp>
#include <Bull/Core/Utility/Size.hpp>

namespace Bull
{
    namespace prv
    {
        class MouseImpl
        {
        public:

            /** \brief Set the position of the cursor on the screen
             *
             * \param position The new position of the cursor on the screen
             *
             */
            static void setPosition(const Size<int>& position);

            /** \brief Get the cursor position
             *
             * \return Return the cursor position
             *
             */
            static Size<int> getPosition();

            /** \brief Check whether a button is pressed
             *
             * \param button The button to check
             *
             * \return True if the button is pressed
             *
             */
            static bool isButtonPressed(MouseButton button);

        private:

            /** \brief Convert a Mouse::Button to a VKey
             *
             * \param button The button to translate
             *
             * \return The VKey
             */
            static int convertBullbuttonToVK(MouseButton button);
        };
    }
}

#endif // BULL_CORE_HARDWARE_WIN32_MOUSEIMPL_HPP

