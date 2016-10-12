#include <Bull/Hardware/Mouse.hpp>
#include <Bull/Hardware/MouseImpl.hpp>

#include <Bull/Window/Window.hpp>

namespace Bull
{
    /*! \brief Set the position of the cursor on the screen
     *
     * \param position The new position of the cursor on the screen
     *
     */
    void Mouse::setPosition(const Vector2I& position)
    {
        prv::MouseImpl::setPosition(position);
    }

    /*! \brief Set the position of the cursor relatively to a window
     *
     * \param position The new position of the cursor relatively to a window
     * \param relativeTo The window
     *
     */
    void Mouse::setPosition(const Vector2I& position, const Window& relativeTo)
    {
        setPosition(relativeTo.getPosition() + position);
    }

    /*! \brief Set the position of the cursor on the screen
     *
     * \param x The new x position of the cursor on the screen
     * \param y The new y position of the cursor on the screen
     *
     */
    void Mouse::setPosition(int x, int y)
    {
        setPosition(Vector2I(x, y));
    }

    /*! \brief Set the position of the cursor relatively to a window
     *
     * \param x The new x position of the cursor relatively to a window
     * \param y The new t position of the cursor relatively to a window
     * \param relativeTo The window
     *
     */
    void Mouse::setPosition(int x, int y, const Window& relativeTo)
    {
        setPosition(relativeTo.getPosition() + Vector2I(x, y));
    }

    /*! \brief Get the cursor position on the screen
     *
     * \return Return the cursor position of the screen
     *
     */
    Vector2I Mouse::getPosition()
    {
        return prv::MouseImpl::getPosition();
    }

    /*! \brief Get the cursor position relatively to a window
     *
     * \param relativeTo The window
     *
     * \return Return the cursor position relatively to a window
     *
     */
    Vector2I Mouse::getPosition(const Window& relativeTo)
    {
        return getPosition() - relativeTo.getPosition();
    }
}
