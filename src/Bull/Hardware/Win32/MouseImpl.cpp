#include <windows.h>

#include <Bull/Hardware/Win32/MouseImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get the cursor position relatively to a window
         *
         * \param relativeTo The window
         *
         * \return Return the cursor position relatively to a window
         *
         */
        void MouseImpl::setPosition(const Vector2I& position)
        {
            SetCursorPos(position.x, position.y);
        }

        /*! \brief Get the cursor position
         *
         * \return Return the cursor position
         *
         */
        Vector2I MouseImpl::getPosition()
        {
            POINT p;

            GetCursorPos(&p);

            return Vector2I(p.x, p.y);
        }
    }
}
