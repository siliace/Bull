#ifndef Bull_MouseImpl_hpp
#define Bull_MouseImpl_hpp

#include <Bull/Hardware/Mouse.hpp>

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

#endif // Bull_MouseImpl_hpp

