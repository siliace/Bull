#ifndef BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP
#define BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP

#include <Bull/Core/Hardware/Mouse.hpp>

namespace Bull
{
    namespace prv
    {
        class MouseImpl
        {
        public:

            /*! \brief Set the position of the cursor on the screen
             *
             * \param position The new position of the cursor on the screen
             *
             */
            static void setPosition(const SizeI& position);

            /*! \brief Get the cursor position
             *
             * \return Return the cursor position
             *
             */
            static SizeI getPosition();

            /*! \brief Check whether a button is pressed
             *
             * \param button The button to check
             *
             * \return True if the button is pressed
             *
             */
            static bool isButtonPressed(MouseButton button);
        };
    }
}

#endif // BULL_CORE_HARDWARE_XLIB_MOUSEIMPL_HPP

