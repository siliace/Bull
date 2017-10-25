#ifndef BULL_CORE_HARDWARE_MOUSE_HPP
#define BULL_CORE_HARDWARE_MOUSE_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Hardware/MouseButton.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    class Window;

    struct BULL_CORE_API Mouse
    {
        /*! \brief Set the position of the cursor on the screen
         *
         * \param position The new position of the cursor on the screen
         *
         */
        static void setPosition(const Vector2I& position);

        /*! \brief Set the position of the cursor on the screen relatively to a Window
         *
         * \param position The position of the cursor
         * \param relative The Window relative to
         *
         */
        static void setPosition(const Vector2I& position, const Window& relative);

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
        static bool isButtonPressed(MouseButton button);
    };
}

#endif // BULL_CORE_HARDWARE_MOUSE_HPP
