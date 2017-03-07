#include <Bull/Render/Viewport.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    Viewport::Viewport() :
        x(0),
        y(0),
        width(0),
        height(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param x
     * \param y
     * \param width
     * \param height
     *
     */
    Viewport::Viewport(int x, int y, int width, int height) :
        Viewport(Vector2I(x, y), Vector2I(width, height))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param position
     * \param size
     *
     */
    Viewport::Viewport(const Vector2I& position, const Vector2I& size) :
        x(position.x),
        y(position.y),
        width(size.x),
        height(size.y)
    {
        /// Nothing
    }

    /*! \brief Compare two viewports
     *
     * \param right The viewport to compare to this one
     *
     * \return Return true if this and right are equal, false otherwise
     *
     */
    bool Viewport::operator==(const Viewport& right) const
    {
        return (x      == right.x) &&
               (y      == right.y) &&
               (width  == right.width) &&
               (height == right.height);
    }

    /*! \brief Compare two viewports
     *
     * \param right The viewport to compare to this one
     *
     * \return Return true if this and right not are equal, false otherwise
     *
     */
    bool Viewport::operator!=(const Viewport& right) const
    {
        return !((*this) == right);
    }

    /*! \brief Move the viewport
     *
     * \param offset The offset to move the viewport
     *
     */
    void Viewport::move(const Vector2I& offset)
    {
        x += offset.x;
        y += offset.y;
    }

    /*! \brief Move the viewport
     *
     * \param x The offset on x-axis
     * \param y The offset on y-axis
     *
     */
    void Viewport::move(int x, int y)
    {
        move(Vector2I(x, y));
    }
}
