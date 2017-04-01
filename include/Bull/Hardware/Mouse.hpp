#ifndef Bull_Mouse_hpp
#define Bull_Mouse_hpp

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    class Window;

    struct BULL_API Mouse
    {
        /*! @brief Set the position of the cursor on the screen
         *
         * @param position The new position of the cursor on the screen
         *
         */
        static void setPosition(const Vector2I& position);

        /*! @brief Set the position of the cursor relatively to a window
         *
         * @param position The new position of the cursor relatively to a window
         * @param relativeTo The window
         *
         */
        static void setPosition(const Vector2I& position, const Window& relativeTo);

        /*! @brief Set the position of the cursor on the screen
         *
         * @param x The new x position of the cursor on the screen
         * @param y The new y position of the cursor on the screen
         *
         */
        static void setPosition(int x, int y);

        /*! @brief Set the position of the cursor relatively to a window
         *
         * @param x The new x position of the cursor relatively to a window
         * @param y The new t position of the cursor relatively to a window
         * @param relativeTo The window
         *
         */
        static void setPosition(int x, int y, const Window& relativeTo);

        /*! @brief Get the cursor position on the screen
         *
         * @return Return the cursor position of the screen
         *
         */
        static Vector2I getPosition();

        /*! @brief Get the cursor position relatively to a window
         *
         * @param relativeTo The window
         *
         * @return Return the cursor position relatively to a window
         *
         */
        static Vector2I getPosition(const Window& relativeTo);

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
    };
}

#endif // Bull_Mouse_hpp
