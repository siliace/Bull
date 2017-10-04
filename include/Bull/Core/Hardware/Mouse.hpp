#ifndef BULL_CORE_MOUSE_HPP
#define BULL_CORE_MOUSE_HPP

#include <Bull/Core/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    struct BULL_CORE_API Mouse
    {
        enum Button
        {
            Right,
            Middle,
            Left,
            Extra1,
            Extra2
        };

        enum Wheel
        {
            Vertical,
            Horizontal
        };

        /*! \brief Set the position of the cursor on the screen
         *
         * \param position The new position of the cursor on the screen
         *
         */
        static void setPosition(const Vector2I& position);

        /*! \brief Set the position of the cursor on the screen
         *
         * \param x The new x position of the cursor on the screen
         * \param y The new y position of the cursor on the screen
         *
         */
        static void setPosition(int x, int y);

        /*! \brief Get the cursor position on the screen
         *
         * \return Return the cursor position of the screen
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
        static bool isButtonPressed(Button button);
    };
}

#endif // BULL_CORE_MOUSE_HPP
