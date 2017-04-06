#ifndef Bull_MouseImpl_hpp
#define Bull_MouseImpl_hpp

#include <Bull/Math/Vector/Vector2.hpp>

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
        };
    }
}

#endif // Bull_MouseImpl_hpp

