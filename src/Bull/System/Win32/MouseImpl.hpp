#ifndef Bull_MouseImpl_hpp
#define Bull_MouseImpl_hpp

#include <Bull/System/Mouse.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

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

        private:

            /*! \brief Convert a Mouse::Button to a VKey
             *
             * \param button The button to translate
             *
             * \return The VKey
             */
            static int convertBullbuttonToVK(Mouse::Button button);
        };
    }
}

#endif // Bull_MouseImpl_hpp

