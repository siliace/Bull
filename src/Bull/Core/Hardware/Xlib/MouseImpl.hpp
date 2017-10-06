#ifndef BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP
#define BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP

#include <Bull/Core/Hardware/Mouse.hpp>

namespace Bull
{
    namespace prv
    {
        struct MouseImpl
        {
            /*! \brief Set the position of the cursor on the screen
             *
             * \param position The new position of the cursor on the screen
             *
             */
            static void setPosition(const Vector2I& position);

            /*! \brief Get the cursor position
             *
             * \return Return the cursor position
             *
             */
            static Vector2I getPosition();

            /*! \brief Check whether a button is pressed
             *
             * \param button The button to check
             *
             * \return True if the button is pressed
             *
             */
            static bool isButtonPressed(Mouse::Button button);
        };
    }
}

#endif // BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP

